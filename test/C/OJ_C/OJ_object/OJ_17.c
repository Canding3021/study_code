#include<stdio.h>
int main(){
    int x=1;    
    while(1){
        if(x%3==2 && x%5==3 && x%7==5 && x>=100){
            printf("%d",x);
            break;
        }
        x++;
    }
    return 0;
}