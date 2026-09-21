#include<stdio.h>
#include<math.h>
int main(){
    int number;
    scanf("%d",&number);
    int g=number%10;
    int s=(number/10)%10;
    int b=number/100;
    int backnumber=g*100+s*10+b;
    int an=number+backnumber;
    printf("%d\n",an);
    return 0;
}


///水仙花数，其背后的原理也差不多。
//只是多了嵌套循环而已。
