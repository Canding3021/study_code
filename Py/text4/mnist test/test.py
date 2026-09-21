import numpy as np
import cupy as cp
import matplotlib.pyplot as plt
from database.mnist import load_mnist
from project import TwoLayerNet
(x_train, t_train), (x_test, t_test) = load_mnist(normalize=True, one_hot_label=True)

x_train_gpu = cp.asarray(x_train)
t_train_gpu = cp.asarray(t_train)
x_test_gpu = cp.asarray(x_test)
t_test_gpu = cp.asarray(t_test)

network = TwoLayerNet(input_size=784, hidden_size=28, output_size=10)

for key in network.params:
    network.params[key] = cp.asarray(network.params[key])

iters_num = 10000  
train_size = x_train.shape[0]
batch_size = 100
learning_rate = 0.0313 #print(np.log1p(np.exp(-1))/10)

train_loss_list = []
train_acc_list = []
test_acc_list = []

iter_per_epoch = max(train_size / batch_size, 1)

for i in range(iters_num):
    batch_mask = cp.random.choice(train_size, batch_size,replace=False)
    x_batch = x_train_gpu[batch_mask]
    t_batch = t_train_gpu[batch_mask]
    
    #grad = network.numerical_gradient(x_batch, t_batch)
    grad = network.gradient(x_batch, t_batch)
    
    for key in ('W1', 'b1', 'W2', 'b2'):
        network.params[key] -= learning_rate * grad[key]
    
    loss = network.loss(x_batch, t_batch)
    if hasattr(loss, 'item'):
        loss = loss.item()
    train_loss_list.append(loss)
    
    if i % iter_per_epoch == 0:
        train_acc_gpu = network.accuracy(x_train_gpu, t_train_gpu)
        test_acc_gpu = network.accuracy(x_test_gpu, t_test_gpu)
        train_acc = float(train_acc_gpu)
        test_acc = float(test_acc_gpu)
        train_acc_list.append(train_acc)
        test_acc_list.append(test_acc)
        print("train acc, test acc | " + str(train_acc) + ", " + str(test_acc))

# 绘制图形
markers = {'train': 'o', 'test': 's'}
x = np.arange(len(train_acc_list))
plt.plot(x, train_acc_list, label='train acc')
plt.plot(x, test_acc_list, label='test acc', linestyle='--')
plt.xlabel("epochs")
plt.ylabel("accuracy")
plt.ylim(0, 1.0)
plt.legend(loc='lower right')
plt.show()
# def smooth_curve(x):
#     """用于平滑损失函数图的简单滤波函数"""
#     window_len = 100  # 窗口大小，数字越大越平滑
#     return np.convolve(x, np.ones(window_len)/window_len, mode='valid')

# # 1. 对数据进行平滑处理
# smoothed_loss = smooth_curve(train_loss_list)
# z = np.arange(len(smoothed_loss))

# # 2. 绘图设置
# plt.figure(figsize=(10, 6)) # 调大图表尺寸
# plt.plot(z, smoothed_loss, color='#1f77b4', linewidth=2, label='Training Loss')

# # 3. 美化细节
# # plt.grid(True, linestyle='--', alpha=0.6) # 添加淡灰色网格线
# # plt.title("Smoothed Training Loss", fontsize=14)
# # plt.xlabel("Iterations", fontsize=12)
# # plt.ylabel("Loss", fontsize=12)
# # plt.legend()
# # plt.show()
W1 = network.params['W1'].get() 

# 2. 创建一个 10x10 的网格来显示这 100 个神经元
fig, axes = plt.subplots(4, 7, figsize=(4, 7))
axes = axes.flatten()

for i in range(28):
    # 将 784 个权重还原成 28x28 的形状
    # 加上适当的色彩映射（如 'coolwarm'）可以更清楚地看到正负权重
    axes[i].imshow(W1[:, i].reshape(28, 28), cmap='coolwarm')
    axes[i].axis('off')

plt.suptitle("W1 Weights Visualization (The patterns neurons look for)")
plt.show()