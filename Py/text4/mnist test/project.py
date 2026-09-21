import numpy as np
def sigmoid(x):
    return 1 / (1 + np.exp(-x))
def identity_function(x):
    return x
def softmax(x):
    if x.ndim == 2:
        x = x.T
        x = x - np.max(x, axis=0)
        y = np.exp(x) / np.sum(np.exp(x), axis=0)
        return y.T 
    c = np.max(x)
    exp_x = np.exp(x - c)
    return exp_x / np.sum(exp_x)
def cross_entropy_error(y, t):
    delta = 1e-7
    return -np.sum(t * np.log(y + delta)) / y.shape[0]
def sigmoid_grad(x):
    return (1.0 - sigmoid(x)) * sigmoid(x)
class TwoLayerNet:
    def __init__(self, input_size, hidden_size, output_size, weight_init_std=0.01):
            # 初始化权重
            self.params = {}
            self.params['W1'] = np.random.randn(input_size, hidden_size) / np.sqrt(input_size)
            self.params['b1'] = np.zeros(hidden_size)
            self.params['W2'] = np.random.randn(hidden_size, output_size) / np.sqrt(hidden_size)
            self.params['b2'] = np.zeros(output_size)

    def predict(self, x):
        W1, W2 = self.params['W1'], self.params['W2']
        b1, b2 = self.params['b1'], self.params['b2']
        
        a1 = np.dot(x, W1) + b1
        z1 = sigmoid(a1)
        a2 = np.dot(z1, W2) + b2
        y = softmax(a2)
            
        return y
            
        # x:输入数据, t:监督数据
    def loss(self, x, t):
        y = self.predict(x)
            
        return cross_entropy_error(y, t)
        
    def accuracy(self, x, t):
        y = self.predict(x)
        y = np.argmax(y, axis=1)
        t = np.argmax(t, axis=1)
            
        accuracy = np.sum(y == t) / float(x.shape[0])
        return accuracy
            
        # x:输入数据, t:监督数据
    def numerical_gradient(self, x, t):
        loss_W = lambda W: self.loss(x, t)
            
        grads = {}
        grads['W1'] = self.numerical_gradient(loss_W, self.params['W1'])
        grads['b1'] = self.numerical_gradient(loss_W, self.params['b1'])
        grads['W2'] = self.numerical_gradient(loss_W, self.params['W2'])
        grads['b2'] = self.numerical_gradient(loss_W, self.params['b2'])
            
        return grads
            
    def gradient(self, x, t):
        W1, W2 = self.params['W1'], self.params['W2']
        b1, b2 = self.params['b1'], self.params['b2']
        grads = {}
            
        batch_num = x.shape[0]
            
        # forward
        a1 = np.dot(x, W1) + b1
        z1 = sigmoid(a1)
        a2 = np.dot(z1, W2) + b2
        y = softmax(a2)
            
        # backward
        dy = (y - t) / batch_num
        grads['W2'] = np.dot(z1.T, dy)
        grads['b2'] = np.sum(dy, axis=0)
            
        da1 = np.dot(dy, W2.T)
        dz1 = sigmoid_grad(a1) * da1
        grads['W1'] = np.dot(x.T, dz1)
        grads['b1'] = np.sum(dz1, axis=0)

        return grads