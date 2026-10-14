# -*- coding: utf-8 -*-
"""生成两份 KNN-Iris 作业 notebook：带注释版 / 简洁版"""
import nbformat as nbf


def code(src):
    return nbf.v4.new_code_cell(src)


def md(src):
    return nbf.v4.new_markdown_cell(src)


# ============================================================
# 版本一：带注释版
# ============================================================
nb1 = nbf.v4.new_notebook()
nb1.cells = [
    md("# 使用 sklearn 的 KNN 对 Iris 数据集进行分类\n\n"
       "**带注释版** —— 每个步骤都有说明，方便对照理解。"),

    md("## 0. 导入所需的库"),
    code(
        "# 导入本次作业需要用到的库\n"
        "from sklearn.datasets import load_iris                       # 加载鸢尾花数据集\n"
        "from sklearn.model_selection import train_test_split         # 划分训练集 / 测试集\n"
        "from sklearn.neighbors import KNeighborsClassifier           # KNN 分类器\n"
        "from sklearn.metrics import accuracy_score, classification_report  # 评估指标\n"
        "import matplotlib.pyplot as plt                              # 绘图\n"
        "\n"
        "# 让 matplotlib 正常显示中文和负号（Windows 用 SimHei）\n"
        "plt.rcParams['font.sans-serif'] = ['SimHei']\n"
        "plt.rcParams['axes.unicode_minus'] = False"
    ),

    md("## 1. 加载 Iris 数据集"),
    code(
        "iris = load_iris()\n"
        "X = iris.data      # 特征矩阵，形状 (150, 4)\n"
        "y = iris.target    # 标签，形状 (150,)\n"
        "\n"
        "print('特征矩阵 X 形状:', X.shape)\n"
        "print('标签 y 形状    :', y.shape)\n"
        "print('四个特征名称   :', iris.feature_names)\n"
        "print('三个类别名称   :', iris.target_names)"
    ),

    md("## 2. 按 8:2 随机划分训练集与测试集"),
    code(
        "# test_size=0.2     -> 测试集占 20%，训练集占 80%\n"
        "# random_state=42   -> 固定随机种子，保证每次运行划分结果一致（可复现）\n"
        "# stratify=y        -> 分层抽样，保证三个类别在训练/测试集中比例一致\n"
        "X_train, X_test, y_train, y_test = train_test_split(\n"
        "    X, y, test_size=0.2, random_state=42, stratify=y)\n"
        "\n"
        "print('训练集样本数:', X_train.shape[0])\n"
        "print('测试集样本数:', X_test.shape[0])"
    ),

    md("## 3. 创建 5 近邻的 KNN 分类器并训练"),
    code(
        "# 创建 5 近邻的 KNN 分类器\n"
        "knn = KNeighborsClassifier(n_neighbors=5)\n"
        "\n"
        "# 训练模型（对 KNN 而言，fit 就是把这批训练样本存进模型）\n"
        "knn.fit(X_train, y_train)"
    ),

    md("## 4. 对测试集预测并计算准确率"),
    code(
        "# 对测试集进行标签预测\n"
        "y_pred = knn.predict(X_test)\n"
        "\n"
        "# 用 accuracy_score 计算准确率\n"
        "acc = accuracy_score(y_test, y_pred)\n"
        "print('预测标签:', y_pred)\n"
        "print('真实标签:', y_test)\n"
        "print('准确率  : %.4f' % acc)\n"
        "\n"
        "# 也可以用 knn.score() 直接得到准确率，结果完全一样\n"
        "print('knn.score() 验证:', knn.score(X_test, y_test))"
    ),

    md("## 5. 打印输出分类报告"),
    code(
        "# classification_report 给出每个类别的 precision / recall / f1-score / support\n"
        "print(classification_report(y_test, y_pred, target_names=iris.target_names))"
    ),

    md("## 6. 取 n_neighbors = 1,3,5,7,9 分别建模并记录准确率"),
    code(
        "# 不同的 k 值会影响模型效果：k 太小对噪声敏感（过拟合），k 太大又过于平滑（欠拟合）\n"
        "k_list = [1, 3, 5, 7, 9]\n"
        "acc_list = []\n"
        "\n"
        "for k in k_list:\n"
        "    model = KNeighborsClassifier(n_neighbors=k)\n"
        "    model.fit(X_train, y_train)\n"
        "    a = model.score(X_test, y_test)\n"
        "    acc_list.append(a)\n"
        "    print('n_neighbors = %d, 准确率 = %.4f' % (k, a))"
    ),

    md("## 7. 绘制不同 n_neighbors 取值下的准确率折线图"),
    code(
        "plt.figure(figsize=(7, 4))\n"
        "plt.plot(k_list, acc_list, marker='o', color='steelblue', label='测试集准确率')\n"
        "\n"
        "# 在每个数据点上方标出具体数值\n"
        "for k, a in zip(k_list, acc_list):\n"
        "    plt.text(k, a + 0.004, '%.3f' % a, ha='center', fontsize=9)\n"
        "\n"
        "plt.xlabel('n_neighbors (k)')\n"
        "plt.ylabel('准确率')\n"
        "plt.title('不同 k 值下 KNN 在 Iris 测试集上的准确率')\n"
        "plt.xticks(k_list)\n"
        "plt.ylim(min(acc_list) - 0.05, max(acc_list) + 0.05)\n"
        "plt.grid(True, linestyle='--', alpha=0.5)\n"
        "plt.legend()\n"
        "plt.show()"
    ),
]

# ============================================================
# 版本二：简洁版（无注释、朴素写法）
# ============================================================
nb2 = nbf.v4.new_notebook()
nb2.cells = [
    code(
        "from sklearn.datasets import load_iris\n"
        "from sklearn.model_selection import train_test_split\n"
        "from sklearn.neighbors import KNeighborsClassifier\n"
        "from sklearn.metrics import accuracy_score, classification_report\n"
        "import matplotlib.pyplot as plt"
    ),
    code(
        "iris = load_iris()\n"
        "X = iris.data\n"
        "y = iris.target\n"
        "X.shape, y.shape"
    ),
    code(
        "X_train, X_test, y_train, y_test = train_test_split(\n"
        "    X, y, test_size=0.2, random_state=42)"
    ),
    code(
        "knn = KNeighborsClassifier(n_neighbors=5)\n"
        "knn.fit(X_train, y_train)"
    ),
    code(
        "y_pred = knn.predict(X_test)\n"
        "print(accuracy_score(y_test, y_pred))"
    ),
    code(
        "print(classification_report(y_test, y_pred))"
    ),
    code(
        "k_list = [1, 3, 5, 7, 9]\n"
        "acc_list = []\n"
        "for k in k_list:\n"
        "    m = KNeighborsClassifier(n_neighbors=k)\n"
        "    m.fit(X_train, y_train)\n"
        "    a = m.score(X_test, y_test)\n"
        "    acc_list.append(a)\n"
        "    print(k, a)"
    ),
    code(
        "plt.plot(k_list, acc_list, marker='o')\n"
        "plt.xlabel('n_neighbors')\n"
        "plt.ylabel('accuracy')\n"
        "plt.show()"
    ),
]

nb1.metadata['kernelspec'] = {'display_name': 'Python 3', 'language': 'python', 'name': 'python3'}
nb2.metadata['kernelspec'] = nb1.metadata['kernelspec']

nbf.write(nb1, 'KNN_Iris_注释版.ipynb')
nbf.write(nb2, 'KNN_Iris_简洁版.ipynb')
print('已生成 KNN_Iris_注释版.ipynb 和 KNN_Iris_简洁版.ipynb')
