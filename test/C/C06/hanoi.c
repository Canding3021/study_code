#include <stdio.h>

int count = 0;  // 记录移动次数

// 将n个盘子从from借助aux移动到to
void hanoi(int n, char from, char aux, char to)
{
    if(n == 1)
    {
        count++;
        printf("第%3d步: 将第 %d 号盘子  %c ----> %c\n", count, n, from, to);
        return;
    }
    hanoi(n - 1, from, to, aux);    // 先将n-1个盘子从from移到aux
    count++;
    printf("第%3d步: 将第 %d 号盘子  %c ----> %c\n", count, n, from, to);  // 将最大的盘子移到to
    hanoi(n - 1, aux, from, to);    // 再将n-1个盘子从aux移到to
}

int main()
{
    int n = 9;
    printf("========== %d 层汉诺塔 ==========\n\n", n);
    printf("初始状态: 所有盘子在 A 柱上\n");
    printf("目标状态: 所有盘子移到 C 柱上\n");
    printf("辅助柱子: B 柱\n\n");
    printf("盘子大小: 1号最小, %d号最大\n\n", n);
    printf("开始移动:\n");
    printf("-----------------------------------\n");

    hanoi(n, 'A', 'B', 'C');

    printf("-----------------------------------\n");
    printf("移动完成! 共需 %d 步\n", count);
    printf("公式验证: 2^%d - 1 = %d\n", n, (1 << n) - 1);

    return 0;
}
