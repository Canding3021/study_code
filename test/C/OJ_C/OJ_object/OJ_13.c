#include<stdio.h>
int main(){
    int num=100007;
    int i=0;
    while(1){
        num+=i;
        int num1=((num+7000000)/10);
        if(num*4==num1){
            printf("%d",num);
            break;
        }
        i+=10;
    }
    return 0;
}