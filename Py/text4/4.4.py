import numpy as np
import matplotlib.pylab as plt

def _numerical_gradient_no_batch(f, x):
    h = 1e-4
    grad = np.zeros_like(x)
    
    for idx in range(x.size):
        tmp_val = x[idx]
        x[idx] = float(tmp_val) + h
        fxh1 = f(x)
        
        x[idx] = tmp_val - h 
        fxh2 = f(x)
        grad[idx] = (fxh1 - fxh2) / (2*h)
        
        x[idx] = tmp_val
        
    return grad

def numerical_gradient(f, X):
    if X.ndim == 1:
        return _numerical_gradient_no_batch(f, X)
    else:
        grad = np.zeros_like(X)
        for idx, x in enumerate(X):
            grad[idx] = _numerical_gradient_no_batch(f, x)
        return grad

def function_2(x):
    if x.ndim == 1:
        return np.sum(x**2)
    else:
        return np.sum(x**2, axis=1)

if __name__ == '__main__':
    x0 = np.arange(-2, 2.5, 0.25)
    x1 = np.arange(-2, 2.5, 0.25)
    X, Y = np.meshgrid(x0, x1)
    
    X_flat = X.flatten()
    Y_flat = Y.flatten()
    
    # 计算梯度
    grad = numerical_gradient(function_2, np.array([X_flat, Y_flat]).T)
    
    plt.figure(figsize=(8, 8))
    
    # 修正点：使用 grad[:, 0] 和 grad[:, 1] 取出所有点的分量
    # 注意：为了指向低处（梯度下降），我们画负梯度 -grad
    plt.quiver(X_flat, Y_flat, -grad[:, 0], -grad[:, 1],  angles="xy", color="#666666")
    
    plt.xlim([-2.5, 2.5])
    plt.ylim([-2.5, 2.5])
    plt.xlabel('x0')
    plt.ylabel('x1')
    plt.title("Gradient Vector Field")
    plt.grid()
    plt.draw()
    plt.show()