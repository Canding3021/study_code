import os, numpy as np
from PIL import Image
from sklearn.neighbors import KNeighborsClassifier

# --- 完全照抄老师 notebook 的 img2array（先 resize 再转灰度）---
def img2array(imgfile, size=(32, 32)):
    img = Image.open(imgfile)
    img = img.resize(size, Image.LANCZOS)
    img = img.convert('L')
    return np.asarray(img).reshape(-1)

# --- 老师的 convert2dataset：改成走你的嵌套目录，其余不变 ---
def convert2dataset(file_path, size=(32, 32)):
    datas, labels = [], []
    for cls in sorted(os.listdir(file_path)):
        d = os.path.join(file_path, cls)
        if not os.path.isdir(d):
            continue
        for f in os.listdir(d):
            labels.append(0 if cls == 'cat' else 1)
            datas.append(img2array(os.path.join(d, f), size=size))
    return np.array(datas), labels

x_train, y_train = convert2dataset('database/train')
x_test, y_test = convert2dataset('database/test')
print('shape:', x_train.shape, x_test.shape)

# --- 照抄老师的归一化 ---
x_train = (x_train - x_train.min(axis=0)) / (x_train.max(axis=0) - x_train.min(axis=0))
x_test = (x_test - x_test.min(axis=0)) / (x_test.max(axis=0) - x_test.min(axis=0))
print('NaN 个数 train/test:', np.isnan(x_train).sum(), np.isnan(x_test).sum())

knn = KNeighborsClassifier(n_neighbors=43, weights='distance', p=2)
knn.fit(x_train, y_train)
print('k=43(distance)  train score = %.4f' % knn.score(x_train, y_train))
print('k=43(distance)  TEST  score = %.4f' % knn.score(x_test, y_test))

# 顺带扫一下 k，看老师为什么选 43
best = max(((k, KNeighborsClassifier(k, weights='distance').fit(x_train, y_train).score(x_test, y_test)) for k in range(1, 101)), key=lambda t: t[1])
print('扫 k=1..100 时 test 最高的是 k=%d, score=%.4f' % best)
