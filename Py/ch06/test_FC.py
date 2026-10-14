import numpy as np
import cupy as cp
import matplotlib.pyplot as plt
from project import TwoLayerNet,load_image

x_train, t_train = load_image('database/train')
x_test, t_test = load_image('database/test')

x_train_gpu = cp.asarray(x_train)
t_train_gpu = cp.asarray(t_train)
x_test_gpu = cp.asarray(x_test)
t_test_gpu = cp.asarray(t_test)

network = TwoLayerNet(input_size=1024,hidden_size=32,output_size=2)

for key in network.params:
    network.params[key] = cp.asarray(network.params[key])

iters_num = 10000
train_size = x_train.shape[0]
batch_size = 16
learning_rate = 0.0313

train_loss_list = []
train_acc_list = []
test_acc_list = []

iter_per_epoch = max(train_size / batch_size, 1)

log_file = open('train_log.txt', 'w', encoding='utf-8')

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
        msg = "train acc, test acc | " + str(train_acc) + ", " + str(test_acc)
        print(msg)
        log_file.write(msg + "\n")
        log_file.flush()

log_file.close()

markers = {'train': 'o', 'test': 's'}
x = np.arange(len(train_acc_list))
plt.plot(x, train_acc_list, label='train acc')
plt.plot(x, test_acc_list, label='test acc', linestyle='--')
plt.xlabel("epochs")
plt.ylabel("accuracy")
plt.ylim(0, 1.0)
plt.legend(loc='lower right')
plt.show()

# W1 = network.params['W1'].get() 
# fig, axes = plt.subplots(4,8, figsize=(4,8 ))
# axes = axes.flatten()

# for i in range(32):
#     axes[i].imshow(W1[:, i].reshape(32, 32), cmap='coolwarm')
#     axes[i].axis('off')
# plt.imshow(W1[:, i].reshape(32, 32), cmap='RdBu_r', vmin=-0.1, vmax=0.1)
# plt.suptitle("W1 Weights Visualization (The patterns neurons look for)")
# plt.show()

#全连接网络在 32×32 灰度图上的天花板约 55%，与 1-NN 的 55.7% 一致。这说明瓶颈不在模型，而在输入表示。要突破必须换表示——即 CNN。