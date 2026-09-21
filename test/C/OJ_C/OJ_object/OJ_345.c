#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int s=2*n+3;
    double an=(double)s/(n*n)*100.0;//在此处要注意整数相除可能导致输出0.0%
    printf("%.1f%%",an);
    return 0;
}