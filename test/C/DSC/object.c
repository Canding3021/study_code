#include <stdio.h>
#include <string.h>

#define MAXSIZE 100  // 栈的最大容量

// 栈结构体
struct Stack {
    char data[MAXSIZE];  // 存放字符的数组
    int top;             // 栈顶位置，-1表示空栈
};

// 初始化栈
void initStack(struct Stack *s) {
    s->top = -1;  // 初始时栈是空的
}

// 判断栈是否为空
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(struct Stack *s) {
    return s->top == MAXSIZE - 1;
}

// 入栈：放一个元素到栈顶
void push(struct Stack *s, char ch) {
    if (isFull(s)) {
        printf("栈满了！\n");
        return;
    }
    s->top++;           // 栈顶上移
    s->data[s->top] = ch;  // 放入元素
}

// 出栈：从栈顶取一个元素
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0';  // 空栈返回空字符
    }
    char ch = s->data[s->top];
    s->top--;         // 栈顶下移
    return ch;
}

// 查看栈顶元素（不取出）
char getTop(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

// 判断两个括号是否匹配
int isMatch(char left, char right) {
    if (left == '(' && right == ')') return 1;
    if (left == '[' && right == ']') return 1;
    if (left == '{' && right == '}') return 1;
    return 0;
}

// 检验括号匹配的主函数
int checkBrackets(char expr[]) {
    struct Stack stack;
    initStack(&stack);
    
    int i;
    char ch, topChar;
    
    // 遍历字符串中的每个字符
    for (i = 0; i < strlen(expr); i++) {
        ch = expr[i];
        
        // 如果是左括号，压入栈
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        }
        // 如果是右括号
        else if (ch == ')' || ch == ']' || ch == '}') {
            // 栈为空，说明没有左括号与之匹配
            if (isEmpty(&stack)) {
                printf("错误：在位置 %d 处发现多余的右括号 '%c'\n", i, ch);
                return 0;
            }
            
            // 取出栈顶元素
            topChar = getTop(&stack);
            
            // 检查是否匹配
            if (isMatch(topChar, ch)) {
                pop(&stack);  // 匹配成功，弹出栈顶
            } else {
                printf("错误：在位置 %d 处，'%c' 和 '%c' 不匹配\n", i, topChar, ch);
                return 0;
            }
        }
    }
    
    // 遍历结束后，检查栈是否还有剩余括号
    if (!isEmpty(&stack)) {
        topChar = getTop(&stack);
        printf("错误：缺少与 '%c' 匹配的右括号\n", topChar);
        return 0;
    }
    
    printf("匹配正确！\n");
    return 1;
}

int main() {
    // 显示个人信息
    printf("========================================\n");
    printf("班级：软件技术1班\n");
    printf("学号：250322226\n");
    printf("姓名：李哲煜\n");
    printf("========================================\n\n");
    
    // 测试数据1：正确匹配
    printf("【测试1】表达式：{[()]}\n");
    printf("结果：");
    checkBrackets("{[()]}");
    
    // 测试数据2：正确匹配（实际代码场景）
    printf("\n【测试2】表达式：if (a[i] == (b + c)) { return true; }\n");
    printf("结果：");
    checkBrackets("if (a[i] == (b + c)) { return true; }");
    
    // 测试数据3：缺少右括号
    printf("\n【测试3】表达式：{[()]\n");
    printf("结果：");
    checkBrackets("{[()]");
    
    // 测试数据4：括号不匹配
    printf("\n【测试4】表达式：([)]\n");
    printf("结果：");
    checkBrackets("([)]");
    
    // 测试数据5：多余的右括号
    printf("\n【测试5】表达式：{(a+b)*[c-d]})\n");
    printf("结果：");
    checkBrackets("{(a+b)*[c-d]})");
    
    printf("\n========================================\n");
    return 0;
}