#include<stdio.h>
int main(){
    double previousBalance;
    double payments;
    double charges;
    double Balance;
    printf("请按照(上次余额、收费、付款)为顺序,输入每位客户的数据:");
    scanf("%lf %lf %lf",&previousBalance,&payments,&charges);
    Balance=previousBalance+payments-charges;
    /*
    此处可以使用三个scanf来分别录入，对程序影响不大.
    */
    printf("月底余额:%.2lf￥",Balance);
    return 0;
}