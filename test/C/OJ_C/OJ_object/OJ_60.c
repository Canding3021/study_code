#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // 输入正整数 n
    int sum = 0;

    if (n % 2 == 1) {  // 如果 n 是奇数
        for (int i = 2; i <= n; i += 2) {  // 从 2 开始，步长为 2，只求偶数
            sum += i;
        }
    } else {  // 如果 n 是偶数
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {  // 如果 i 是 n 的约数
                sum += i;
            }
        }
    }

    printf("%d\n", sum);  // 输出结果
    return 0;
}
