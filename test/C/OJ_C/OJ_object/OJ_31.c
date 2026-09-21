//摄氏度华氏度转换
#include<stdio.h>
#include<math.h>
int main(){
    int C;
    scanf("%d",&C);
    double F=9.0/5.0*C+32;///在这里，需要写成9.0/5.0而非9/5，后者会导致整数*1
    printf("%.2f",F);
    return 0;
}