import numpy as np, cupy as cp

# 只取 test_CNN.py 里"训练"之前的定义部分来测，避免触发整段训练
src = open('test_CNN.py', encoding='utf-8').read()
src = src.split('# ---------------------------------------------------------------- 训练')[0]
ns = {}
exec(compile(src, 'test_CNN.py', 'exec'), ns)
SimpleConvNet = ns['SimpleConvNet']

cp.random.seed(0)
net = SimpleConvNet(input_dim=(1, 8, 8), hidden_size=6, output_size=2, use_dropout=False)
rng = np.random.RandomState(0)
x = cp.asarray(rng.randn(3, 1, 8, 8).astype(np.float32))
t = cp.asarray(np.eye(2)[[0, 1, 0]].astype(np.float32))

grads = net.gradient(x, t)
print('grad keys:', sorted(grads))
print('grad shapes ok:', all(grads[k].shape == net.params[k].shape for k in grads))

eps = 1e-4
worst = 0.0
for key in sorted(net.params):
    p = net.params[key].reshape(-1)
    n = p.size
    idx = rng.choice(n, min(4, n), replace=False)
    for i in idx:
        orig = float(p[i])
        p[i] = orig + eps; lp = float(net.loss(x, t))
        p[i] = orig - eps; lm = float(net.loss(x, t))
        p[i] = orig
        num = (lp - lm) / (2 * eps)
        ana = float(grads[key].reshape(-1)[i])
        denom = max(abs(num), abs(ana), 1e-8)
        rel = abs(num - ana) / denom
        worst = max(worst, rel)
        print('%-3s[%d]  numerical %+.6f  analytical %+.6f  rel.err %.2e' % (key, i, num, ana, rel))
print('\nworst relative error = %.3e  ->  %s' % (worst, 'PASS' if worst < 1e-3 else 'FAIL'))
