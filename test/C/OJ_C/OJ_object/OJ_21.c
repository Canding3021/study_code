#include<stdio.h>
int main(){
    int x=1;
    while(x<=500){
        if( x%3==2 && x%5==3 && x%7==2 && x>=1){
            printf("%d\n",x);
        }
        x++;
    }
    return 0;
}