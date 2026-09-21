#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;//需要定义一变量（初始化）
    while(n){
        sum+=n%10;
        n/=10;              //他妈的，太神奇了，拆数字大法万岁！！！！
    }
    printf("%d",sum);
    return 0;
}