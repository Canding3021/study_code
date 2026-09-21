#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    if(num<10){
        printf("A");
    }
    else if(num<20){
        printf("B");
    }
    else if(num<40){
        printf("C");
    }
    else if (num<50){
        printf("D");
    }
    else if (num<80){
        printf("E");
    }


    return 0;
}