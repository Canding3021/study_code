#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        for(int n=0;n<i+1;n++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}