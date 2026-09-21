#include <stdio.h>
int main()
{
    int a[20] = {12, 35, 28, 41, 56, 73, 84, 97, 10, 23,
                 46, 59, 68, 77, 90, 15, 32, 51, 64, 85};
    int b[2][20];
    int even_count = 0;
    int odd_count = 0;
    for(int i = 0; i < 20; i++)
    {
        if(a[i] % 2 == 0)
        {
            b[0][even_count] = a[i];
            even_count++;
        }
        else
        {
            b[1][odd_count] = a[i];
            odd_count++;
        }
    }
    printf("二维数组b的内容:\n");
    printf("第1行(偶数):");
    for(int i = 0; i < even_count; i++)
    {
        printf("%d ", b[0][i]);
    }
    printf("\n");
    printf("第2行(奇数):");
    for(int i = 0; i < odd_count; i++)
    {
        printf("%d ", b[1][i]);
    }
    printf("\n");
    return 24;
}