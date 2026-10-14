"""CNN 版猫狗分类（从零手写，cupy 实现）。
和 test_FC.py 的区别：
  1. 不再把图片拉平成一维像素，而是用卷积层直接在 (3, 32, 32) 的彩色图上滑动；
  2. 用彩色（RGB）而不是灰度 —— 毛色/花色本身就是很强的判别信息。
结构：Conv-ReLU-Pool -> Conv-ReLU-Pool -> Affine-ReLU -> Affine -> Softmax
"""
import os
import numpy as np
import cupy as cp
import matplotlib.pyplot as plt
from collections import OrderedDict
from PIL import Image


def load_image_color(data_dir, size=(32, 32)):
    """彩色版数据加载，返回 (N, 3, H, W) —— 卷积网络要的形状，不拉平。
    和 project.load_image 的区别：那个 convert('L') 转灰度再 reshape(-1)，
    这个是 convert('RGB') 并把通道放到最前面。
    """
    X, T = [], []
    for cls_name in os.listdir(data_dir):
        cls_dir = os.path.join(data_dir, cls_name)
        if not os.path.isdir(cls_dir):
            continue
        if cls_name == 'cat':
            label = 0
        elif cls_name == 'dog':
            label = 1
        else:
            continue
        for fname in os.listdir(cls_dir):
            if not fname.lower().endswith(('.jpg', '.png', '.jpeg')):
                continue
            img = Image.open(os.path.join(cls_dir, fname)).convert('RGB')
            img = img.resize(size, Image.LANCZOS)
            arr = np.asarray(img, dtype=np.float32) / 255.0    # (H, W, 3)
            X.append(arr.transpose(2, 0, 1))                   # -> (3, H, W)
            T.append(label)
    X = np.array(X)
    T = np.eye(2)[np.array(T, dtype=np.int64)]
    return X, T


# ---------------------------------------------------------------- im2col / col2im
def im2col(input_data, filter_h, filter_w, stride=1, pad=0):
    """把图像按滑动窗口"摊开"成大矩阵，这样卷积就能用一次矩阵乘法算完。"""
    N, C, H, W = input_data.shape
    out_h = (H + 2 * pad - filter_h) // stride + 1
    out_w = (W + 2 * pad - filter_w) // stride + 1

    img = cp.pad(input_data, [(0, 0), (0, 0), (pad, pad), (pad, pad)], 'constant')
    col = cp.zeros((N, C, filter_h, filter_w, out_h, out_w), dtype=input_data.dtype)

    for y in range(filter_h):
        y_max = y + stride * out_h
        for x in range(filter_w):
            x_max = x + stride * out_w
            col[:, :, y, x, :, :] = img[:, :, y:y_max:stride, x:x_max:stride]

    col = col.transpose(0, 4, 5, 1, 2, 3).reshape(N * out_h * out_w, -1)
    return col


def col2im(col, input_shape, filter_h, filter_w, stride=1, pad=0):
    """im2col 的逆操作：把摊开的梯度再叠回原图，用于反向传播。"""
    N, C, H, W = input_shape
    out_h = (H + 2 * pad - filter_h) // stride + 1
    out_w = (W + 2 * pad - filter_w) // stride + 1
    col = col.reshape(N, out_h, out_w, C, filter_h, filter_w).transpose(0, 3, 4, 5, 1, 2)

    img = cp.zeros((N, C, H + 2 * pad + stride - 1, W + 2 * pad + stride - 1), dtype=col.dtype)
    for y in range(filter_h):
        y_max = y + stride * out_h
        for x in range(filter_w):
            x_max = x + stride * out_w
            img[:, :, y:y_max:stride, x:x_max:stride] += col[:, :, y, x, :, :]

    return img[:, :, pad:H + pad, pad:W + pad]


# ---------------------------------------------------------------- 各种层
class Convolution:
    def __init__(self, W, b, stride=1, pad=0):
        self.W, self.b = W, b
        self.stride, self.pad = stride, pad
        self.x = self.col = self.col_W = None

    def forward(self, x):
        FN, C, FH, FW = self.W.shape
        N, C, H, W = x.shape
        out_h = (H + 2 * self.pad - FH) // self.stride + 1
        out_w = (W + 2 * self.pad - FW) // self.stride + 1

        col = im2col(x, FH, FW, self.stride, self.pad)
        col_W = self.W.reshape(FN, -1).T
        out = cp.dot(col, col_W) + self.b
        out = out.reshape(N, out_h, out_w, -1).transpose(0, 3, 1, 2)

        self.x, self.col, self.col_W = x, col, col_W
        return out

    def backward(self, dout):
        FN, C, FH, FW = self.W.shape
        dout = dout.transpose(0, 2, 3, 1).reshape(-1, FN)
        self.db = cp.sum(dout, axis=0)
        dW = cp.dot(self.col.T, dout)
        self.dW = dW.transpose(1, 0).reshape(FN, C, FH, FW)
        dcol = cp.dot(dout, self.col_W.T)
        dx = col2im(dcol, self.x.shape, FH, FW, self.stride, self.pad)
        return dx


class Relu:
    def forward(self, x):
        self.mask = (x <= 0)
        out = x.copy()
        out[self.mask] = 0
        return out

    def backward(self, dout):
        dout = dout.copy()
        dout[self.mask] = 0
        return dout


class Pooling:
    """最大池化：把 2x2 区域压成 1 个最大值，图变小、抗小位移。"""
    def __init__(self, pool_h, pool_w, stride=1, pad=0):
        self.pool_h, self.pool_w = pool_h, pool_w
        self.stride, self.pad = stride, pad
        self.x = self.arg_max = None

    def forward(self, x):
        N, C, H, W = x.shape
        out_h = (H - self.pool_h) // self.stride + 1
        out_w = (W - self.pool_w) // self.stride + 1

        col = im2col(x, self.pool_h, self.pool_w, self.stride, self.pad)
        col = col.reshape(-1, self.pool_h * self.pool_w)

        self.arg_max = cp.argmax(col, axis=1)
        out = cp.max(col, axis=1)
        out = out.reshape(N, out_h, out_w, C).transpose(0, 3, 1, 2)

        self.x = x
        return out

    def backward(self, dout):
        dout = dout.transpose(0, 2, 3, 1)
        pool_size = self.pool_h * self.pool_w
        dmax = cp.zeros((dout.size, pool_size), dtype=dout.dtype)
        dmax[cp.arange(self.arg_max.size), self.arg_max] = dout.flatten()
        dmax = dmax.reshape(dout.shape + (pool_size,))
        dcol = dmax.reshape(dmax.shape[0] * dmax.shape[1] * dmax.shape[2], -1)
        return col2im(dcol, self.x.shape, self.pool_h, self.pool_w, self.stride, self.pad)


class Affine:
    def __init__(self, W, b):
        self.W, self.b = W, b
        self.x = None

    def forward(self, x):
        self.x_shape = x.shape
        self.x = x.reshape(x.shape[0], -1)
        return cp.dot(self.x, self.W) + self.b

    def backward(self, dout):
        self.dW = cp.dot(self.x.T, dout)
        self.db = cp.sum(dout, axis=0)
        return cp.dot(dout, self.W.T).reshape(*self.x_shape)


class Dropout:
    """随机丢掉一部分神经元，逼网络别只靠少数几个特征（抗过拟合）。"""
    def __init__(self, ratio=0.5):
        self.ratio = ratio
        self.mask = None

    def forward(self, x, train_flg=True):
        if not train_flg:
            return x
        self.mask = cp.random.rand(*x.shape) > self.ratio
        return x * self.mask

    def backward(self, dout):
        return dout * self.mask


def softmax(x):
    if x.ndim == 2:
        x = x - x.max(axis=1, keepdims=True)
        y = cp.exp(x) / cp.sum(cp.exp(x), axis=1, keepdims=True)
        return y
    x = x - cp.max(x)
    return cp.exp(x) / cp.sum(cp.exp(x))


def cross_entropy_error(y, t):
    delta = 1e-7
    return -cp.sum(t * cp.log(y + delta)) / y.shape[0]


class SoftmaxWithLoss:
    def forward(self, x, t):
        self.t = t
        self.y = softmax(x)
        self.loss = cross_entropy_error(self.y, self.t)
        return self.loss

    def backward(self, dout=1):
        return (self.y - self.t) / self.t.shape[0]


# ---------------------------------------------------------------- 优化器
class Adam:
    def __init__(self, lr=0.001, beta1=0.9, beta2=0.999):
        self.lr, self.beta1, self.beta2 = lr, beta1, beta2
        self.iter = 0
        self.m, self.v = None, None

    def update(self, params, grads):
        if self.m is None:
            self.m = {k: cp.zeros_like(v) for k, v in params.items()}
            self.v = {k: cp.zeros_like(v) for k, v in params.items()}

        self.iter += 1
        lr_t = self.lr * cp.sqrt(1.0 - self.beta2 ** self.iter) / (1.0 - self.beta1 ** self.iter)

        for key in params.keys():
            self.m[key] += (1 - self.beta1) * (grads[key] - self.m[key])
            self.v[key] += (1 - self.beta2) * (grads[key] ** 2 - self.v[key])
            params[key] -= lr_t * self.m[key] / (cp.sqrt(self.v[key]) + 1e-7)


# ---------------------------------------------------------------- 网络
class SimpleConvNet:
    def __init__(self, input_dim=(1, 32, 32), conv_param=None,
                 hidden_size=64, output_size=2, use_dropout=False):
        if conv_param is None:
            conv_param = {'filter_num': 32, 'filter_size': 3, 'pad': 1, 'stride': 1}
        self.use_dropout = use_dropout

        filter_num = conv_param['filter_num']
        filter_size = conv_param['filter_size']
        filter_pad = conv_param['pad']
        filter_stride = conv_param['stride']

        # 每次 3x3 pad1 stride1 -> 尺寸不变；后面跟一次 2x2 pool -> 尺寸减半
        conv1_out = input_dim[1]
        conv2_out = conv1_out // 2
        h1 = conv2_out // 2
        pool_output_size = filter_num * h1 * h1

        self.params = {}
        # He 初始化（配 ReLU 用）
        self.params['W1'] = cp.random.randn(filter_num, input_dim[0], filter_size, filter_size) \
            * cp.sqrt(2.0 / (filter_size * filter_size * input_dim[0]))
        self.params['b1'] = cp.zeros(filter_num)
        self.params['W2'] = cp.random.randn(filter_num, filter_num, filter_size, filter_size) \
            * cp.sqrt(2.0 / (filter_size * filter_size * filter_num))
        self.params['b2'] = cp.zeros(filter_num)
        self.params['W3'] = cp.random.randn(pool_output_size, hidden_size) * cp.sqrt(2.0 / pool_output_size)
        self.params['b3'] = cp.zeros(hidden_size)
        self.params['W4'] = cp.random.randn(hidden_size, output_size) * cp.sqrt(2.0 / hidden_size)
        self.params['b4'] = cp.zeros(output_size)

        self.layers = OrderedDict()
        self.layers['Conv1'] = Convolution(self.params['W1'], self.params['b1'], filter_stride, filter_pad)
        self.layers['Relu1'] = Relu()
        self.layers['Pool1'] = Pooling(2, 2, 2)
        self.layers['Conv2'] = Convolution(self.params['W2'], self.params['b2'], filter_stride, filter_pad)
        self.layers['Relu2'] = Relu()
        self.layers['Pool2'] = Pooling(2, 2, 2)
        self.layers['Affine1'] = Affine(self.params['W3'], self.params['b3'])
        self.layers['Relu3'] = Relu()
        if use_dropout:
            self.layers['Dropout'] = Dropout(0.5)
        self.layers['Affine2'] = Affine(self.params['W4'], self.params['b4'])

        self.last_layer = SoftmaxWithLoss()

    def predict(self, x, train_flg=False):
        for layer in self.layers.values():
            if isinstance(layer, Dropout):
                x = layer.forward(x, train_flg)
            else:
                x = layer.forward(x)
        return x

    def loss(self, x, t):
        y = self.predict(x, train_flg=True)
        return self.last_layer.forward(y, t)

    def accuracy(self, x, t):
        y = self.predict(x, train_flg=False)
        y = cp.argmax(y, axis=1)
        t = cp.argmax(t, axis=1)
        return float(cp.sum(y == t) / x.shape[0])

    def gradient(self, x, t):
        self.loss(x, t)

        dout = self.last_layer.backward(1)

        layers = list(self.layers.values())
        layers.reverse()
        for layer in layers:
            dout = layer.backward(dout)

        grads = {}
        grads['W1'], grads['b1'] = self.layers['Conv1'].dW, self.layers['Conv1'].db
        grads['W2'], grads['b2'] = self.layers['Conv2'].dW, self.layers['Conv2'].db
        grads['W3'], grads['b3'] = self.layers['Affine1'].dW, self.layers['Affine1'].db
        grads['W4'], grads['b4'] = self.layers['Affine2'].dW, self.layers['Affine2'].db
        return grads


# ---------------------------------------------------------------- 训练
IMAGE_SIZE = (32, 32)  # 想再往上推就改成 (64, 64)，网络结构会自动跟着变
USE_DROPOUT = True     # 上一版 MLP 过拟合了，这里默认开 dropout
EPOCHS = 40
BATCH_SIZE = 16
LR = 0.001

x_train, t_train = load_image_color('database/train', IMAGE_SIZE)
x_test, t_test = load_image_color('database/test', IMAGE_SIZE)

# load_image_color 已经返回 (N, 3, H, W)，直接搬到 GPU 就行
x_train = cp.asarray(x_train, dtype=cp.float32)
x_test = cp.asarray(x_test, dtype=cp.float32)
t_train = cp.asarray(t_train, dtype=cp.float32)
t_test = cp.asarray(t_test, dtype=cp.float32)

network = SimpleConvNet(input_dim=(3, IMAGE_SIZE[0], IMAGE_SIZE[1]),
                        hidden_size=64, output_size=2,
                        use_dropout=USE_DROPOUT)
optimizer = Adam(lr=LR)

train_size = x_train.shape[0]
iters_per_epoch = max(train_size // BATCH_SIZE, 1)

log_file = open('cnn_log.txt', 'w', encoding='utf-8')
train_acc_list, test_acc_list = [], []

for epoch in range(EPOCHS):
    perm = cp.random.permutation(train_size)
    for i in range(iters_per_epoch):
        idx = perm[i * BATCH_SIZE:(i + 1) * BATCH_SIZE]
        x_batch = x_train[idx]
        t_batch = t_train[idx]

        # 简单数据增强：一半的图左右翻转（猫狗翻转后还是猫狗）
        flip = cp.random.rand(len(idx)) < 0.5
        x_batch[flip] = x_batch[flip][:, :, :, ::-1]

        grads = network.gradient(x_batch, t_batch)
        optimizer.update(network.params, grads)

    train_acc = network.accuracy(x_train, t_train)
    test_acc = network.accuracy(x_test, t_test)
    train_acc_list.append(train_acc)
    test_acc_list.append(test_acc)

    msg = "epoch %2d/%d | train acc %.4f, test acc %.4f" % (epoch + 1, EPOCHS, train_acc, test_acc)
    print(msg)
    log_file.write(msg + "\n")
    log_file.flush()

log_file.close()

plt.plot(np.arange(len(train_acc_list)), train_acc_list, label='train acc')
plt.plot(np.arange(len(test_acc_list)), test_acc_list, label='test acc', linestyle='--')
plt.xlabel("epochs")
plt.ylabel("accuracy")
plt.ylim(0, 1.0)
plt.legend(loc='lower right')
plt.show()

# 看第一层卷积学到的 32 个 3x3 滤波器长什么样
W1 = cp.asnumpy(network.params['W1'])   # (32, 1, 3, 3)
fig, axes = plt.subplots(4, 8, figsize=(8, 4))
for i, ax in enumerate(axes.flatten()):
    ax.imshow(W1[i, 0], cmap='coolwarm')
    ax.axis('off')
plt.suptitle("Conv1 filters (what each of the 32 neurons looks for)")
plt.show()
