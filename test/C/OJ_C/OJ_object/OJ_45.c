#include<stdio.h>
int main(){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    if(x+y<=z || x+z<=y || y+z<=x ){
        printf("No");
    }
    else
        printf("Yes");





    return 0;
}