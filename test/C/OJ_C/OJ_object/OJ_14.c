#include<stdio.h>
int main(){
    int number;
    scanf("%d",&number);
    double output=0;    //定义函数
    for(int i=1;i<=number;i++){
        output+=(double)(1.0/i);   //运算
    }
    printf("%.3lf\r",output);
    return 0;
}