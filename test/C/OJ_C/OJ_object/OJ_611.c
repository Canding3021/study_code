#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i=100000;i>0;i/=10){
        int number=num/i;
        printf("%d\n",number);
        num=num%i;
    }
    return 0;
}