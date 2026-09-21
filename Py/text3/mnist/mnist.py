import gzip
import numpy as np
import os

# 定义文件名对应关系
key_file = {
    'train_img':'train-images-idx3-ubyte.gz',
    'train_label':'train-labels-idx1-ubyte.gz',
    'test_img':'t10k-images-idx3-ubyte.gz',
    'test_label':'t10k-labels-idx1-ubyte.gz'
}

def load_mnist(normalize=True, flatten=True, one_hot_label=False):
    # 假设你的 .gz 文件就在当前目录下的 database 文件夹里
    container = "database" 
    dataset = {}

    # 读取图像
    for key in ('train_img', 'test_img'):
        file_path = os.path.join(os.path.dirname(__file__), container, key_file[key])
        with gzip.open(file_path, 'rb') as f:
            dataset[key] = np.frombuffer(f.read(), np.uint8, offset=16)
    
    # 读取标签
    for key in ('train_label', 'test_label'):
        file_path = os.path.join(os.path.dirname(__file__), container, key_file[key])
        with gzip.open(file_path, 'rb') as f:
            dataset[key] = np.frombuffer(f.read(), np.uint8, offset=8)

    # 处理：展平 (Flatten)
    if flatten:
        for key in ('train_img', 'test_img'):
            dataset[key] = dataset[key].reshape(-1, 784)
    else:
        for key in ('train_img', 'test_img'):
            dataset[key] = dataset[key].reshape(-1, 1, 28, 28)

    # 处理：标准化 (Normalize)
    if normalize:
        for key in ('train_img', 'test_img'):
            dataset[key] = dataset[key].astype(np.float32) / 255.0

    # 处理：独热编码 (One-Hot) - 这里为了简单先不写复杂的转换
    if one_hot_label:
        def _change_one_hot_label(X):
            T = np.zeros((X.size, 10))
            for idx, row in enumerate(T):
                row[X[idx]] = 1
            return T
        dataset['train_label'] = _change_one_hot_label(dataset['train_label'])
        dataset['test_label'] = _change_one_hot_label(dataset['test_label'])

    return (dataset['train_img'], dataset['train_label']), \
           (dataset['test_img'], dataset['test_label'])