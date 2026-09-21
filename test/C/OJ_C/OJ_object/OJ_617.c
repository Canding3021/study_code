#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int sum=0;
    int num1=num;
    for(int i=1000;i>0;i/=10){
        sum+=(num1/i);
        num1%=i;
    } 
    printf("%d",(num+sum));
    return 0;
}