/*
#include<stdio.h>
int main(){
        int a;
    scanf("%d",&a);
    int num[100];
    int i=0;
    while(a>0){
        num[i]=a%10;
        a/=10;
        i++;
    }//你不用管为什么我拿100来决定循环上线，因为num[100]里最多能放100
    //下面的输出不会写
    for(int j = i - 1; j >= 0; j--){
        printf("%d", num[j]);
    return 0;
}
    */
#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int ge=a%10;
    int shi=(a/10)%10;
    int an=ge*10+shi;
    printf("%d",an);




    return 0;
}