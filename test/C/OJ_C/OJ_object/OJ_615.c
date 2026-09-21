#include <stdio.h>
int main() {
    int num;
    scanf("%d", &num);
    int bai = num / 100;    
    int ge = num % 10;     
    int result = bai*10 + ge;
    printf("%d\n", result);

    return 0;
}