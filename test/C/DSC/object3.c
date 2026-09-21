#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node* root = NULL;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preOrderTraversal(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
void inOrderTraversal(Node* node) {
    if (node == NULL) return;
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}
void postOrderTraversal(Node* node) {
    if (node == NULL) return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d ", node->data);
}

int countLeafNodes(Node* node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}
void printRotatedTree(Node* node, int level) {
    if (node == NULL) return;
    printRotatedTree(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", node->data);
    printRotatedTree(node->left, level + 1);
}
void freeTree(Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
void buildCustomTree() {
    int choice;
    printf("\n--- 建立二叉树 ---\n");
    printf("请选择：\n");
    printf("  1. 使用示例二叉树 (10,5,15,2,7)\n");
    printf("  2. 手动输入构建二叉树(不会做)\n");
    printf("请输入选择: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        // 释放旧树
        freeTree(root);
        
        // 构建示例二叉树
        root = createNode(10);
        root->left = createNode(5);
        root->right = createNode(15);
        root->left->left = createNode(2);
        root->left->right = createNode(7);
        
        printf("已成功建立示例二叉树：\n");
        printf("        10\n");
        printf("       /  \\\n");
        printf("      5    15\n");
        printf("     / \\\n");
        printf("    2   7\n");
    } else if(choice==2){
        printf("无效选择，使用默认示例树。\n");
        root = createNode(10);
        root->left = createNode(5);
        root->right = createNode(15);
        root->left->left = createNode(2);
        root->left->right = createNode(7);
    }
    else {
        printf("无效选择，使用默认示例树。\n");
        root = createNode(10);
        root->left = createNode(5);
        root->right = createNode(15);
        root->left->left = createNode(2);
        root->left->right = createNode(7);
    }
}
void displayMenu() {
    printf("\n\n========================================\n");
    printf("       二叉树操作菜单\n");
    printf("========================================\n");
    printf(" 1. 建立/重置二叉树\n");
    printf(" 2. 输出先根遍历 (Pre-order)\n");
    printf(" 3. 输出中根遍历 (In-order)\n");
    printf(" 4. 输出后根遍历 (Post-order)\n");
    printf(" 5. 统计叶子结点数\n");
    printf(" 6. 逆时针旋转90度并打印(没做呢)\n");
    printf(" 0. 退出程序\n");
    printf("========================================\n");
    printf("请选择操作: ");
}
int main() {
    int choice;
    printf("软件技术1班，250322226，李哲煜");
    root = NULL;
    
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = -1;
        }
        switch (choice) {
            case 1:
                buildCustomTree();
                break;
            case 2:
                if (root != NULL) {
                    printf("\n--- 先根遍历结果 (Pre-order) ---\n");
                    printf("遍历序列: ");
                    preOrderTraversal(root);
                    printf("\n");
                } else {
                    printf("\n错误：请先建立二叉树（选择操作1）。\n");
                }
                break;
            case 3:
                if (root != NULL) {
                    printf("\n--- 中根遍历结果 (In-order) ---\n");
                    printf("遍历序列: ");
                    inOrderTraversal(root);
                    printf("\n");
                } else {
                    printf("\n错误：请先建立二叉树（选择操作1）。\n");
                }
                break;
            case 4:
                if (root != NULL) {
                    printf("\n--- 后根遍历结果 (Post-order) ---\n");
                    printf("遍历序列: ");
                    postOrderTraversal(root);
                    printf("\n");
                } else {
                    printf("\n错误：请先建立二叉树（选择操作1）。\n");
                }
                break;
            case 5:
                if (root != NULL) {
                    int leafCount = countLeafNodes(root);
                    printf("\n--- 叶子结点统计 ---\n");
                    printf("该二叉树共有 %d 个叶子结点。\n", leafCount);
                } else {
                    printf("\n错误：请先建立二叉树（选择操作1）。\n");
                }
                break;
            case 6:
                printf("\n--- 逆时针旋转90度凹入表示法 ---\n");
                printf("没做");
                break;
            case 0:
                printf("\n正在退出程序...\n");
                break;
            default:
                printf("\n无效选择！请重新输入（0-6）。\n");
                break;
        }
    } while (choice != 0);
    freeTree(root);
    return 0;
}