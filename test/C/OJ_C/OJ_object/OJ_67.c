#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        for(int l=0;l<i;l++){
            printf(" ");
        }
        for(int n=0;n<num;n++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}