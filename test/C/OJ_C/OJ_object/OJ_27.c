#include<stdio.h>
#include<math.h>
int main(){
    int num;
    scanf("%d",&num);
    int g=num%10;
    int s=(num/10)%10;
    int b=num/100;
    int an=g+s+b;
    printf("%d",an);

    return 0;
}