import numpy as np
from project import load_image

xtr, ttr = load_image('database/train')
xte, tte = load_image('database/test')
ytr, yte = ttr.argmax(1), tte.argmax(1)

print('train', xtr.shape, 'cat/dog =', np.bincount(ytr))
print('test ', xte.shape, 'cat/dog =', np.bincount(yte))
print('majority-class baseline on test =', np.bincount(yte).max()/len(yte))

# 分布差异：整体亮度
print('train pix mean/std = %.4f / %.4f' % (xtr.mean(), xtr.std()))
print('test  pix mean/std = %.4f / %.4f' % (xte.mean(), xte.std()))

# 1-NN 最近邻（原始像素 L2）
d = ((xte[:, None, :] - xtr[None, :, :]) ** 2).sum(-1)
nn = d.argmin(1)
print('1-NN (raw pixel L2) test acc = %.4f' % (ytr[nn] == yte).mean())

# 类均值分类器
mc, md = xtr[ytr == 0].mean(0), xtr[ytr == 1].mean(0)
print('class-mean L2 distance cat-vs-dog = %.4f' % np.sqrt(((mc - md) ** 2).sum()))
sc = ((xtr - mc) ** 2).sum(1); sd = ((xtr - md) ** 2).sum(1)
print('class-mean classifier train acc = %.4f' % ((sc > sd).astype(int) == ytr).mean())

# 同一张图重复？train 里有没有测试图
print('train 内部重复图数量 =', len(xtr) - len(np.unique(xtr, axis=0)))
