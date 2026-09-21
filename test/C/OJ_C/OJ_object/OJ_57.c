#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int count = 0;
    
    // 遍历 1 到 N 的所有数字
    for (int i = 1; i <= N; i++) {
        // 判断数字是否能被 5 整除
        if (i % 5 == 0) {
            int temp = i;
            // 检查数字中是否包含数字 '5'
            while (temp > 0) {
                if (temp % 10 == 5) {
                    count++;  // 如果有数字 '5'，计数加 1
                    break;    // 找到一个 '5' 后跳出循环
                }
                temp /= 10;  // 除以 10，检查下一位
            }
        }
    }
    
    printf("%d", count);  // 输出符合条件的数字个数
    return 0;
}
