#include <stdio.h>
long sum(int m, int a)
{
    long total = 0;
    long term = 0;
    int i;
    for(i = 1; i <= m; i++)
    {
        term = term * 10 + a;
        total = total + term;
    }
    return total;
}
int main()
{
    int a, m;
    long result;
    printf("请输入数字a (1-9): ");
    scanf("%d", &a);
    printf("请输入项数m: ");
    scanf("%d", &m);
    result = sum(m, a);
    printf("s = ");
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%d", a);
        }
        if(i < m)
            printf(" + ");
    }
    printf(" = %ld\n", result);
    return 26;
}