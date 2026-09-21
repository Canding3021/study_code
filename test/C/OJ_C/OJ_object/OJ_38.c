#include<stdio.h>
int main(){
    long x;
    scanf("%ld",&x);
    if(x==0){
        printf("0");
    }
    else if(x<0){
        printf("%ld",(x-1));
    }
    else if(x>0){
        printf("%ld",(x+1));
    }


    return 0;
}