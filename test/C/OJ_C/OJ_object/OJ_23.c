#include<stdio.h>
int main(){
    int number;
    scanf("%d",&number);
    int x=2;
    int valid=1;
    if(number <= 1){
        printf("F");
        return 0;
    }
    while(x<number){
        if(number%x==0){
            valid=0;
            break;
        }
        x++;
    }
    if(valid==1){
        printf("T");
    }
    else
        printf("F");
    return 0;
}