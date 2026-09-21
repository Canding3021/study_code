#include<stdio.h>
int main(){
    int x=0;
    int i=1;
    while(1){
        int y=(50-x);
        if(2*x+4*y==160){
            printf("%d %d",x,y);
            break;
        }
        x+=i;
    }
    return 0;
}