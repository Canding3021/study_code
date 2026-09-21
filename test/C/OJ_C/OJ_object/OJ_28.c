#include<stdio.h>
#include<math.h>
int main(){
    int num;
    scanf("%d",&num);
    int ge=num%10;
    int shi=(num/10)%10;
    int bai=num/100;
    int an=ge*100+shi*10+bai;
    printf("%d\n",an);
    return 0;
}

//有一说一，这玩意和OJ_20.c里的代码真的像，我还是不会提取每个数字中的位数，这个只能写3位数
//如果数字大上去了，我这个代码就是屎山。。。