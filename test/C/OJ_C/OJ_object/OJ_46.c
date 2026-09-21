#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}   
int main(){
    int num[4];
    for(int i=0;i<4;i++){
        scanf("%d",&num[i]);
    }
    qsort(num,4,sizeof(int),cmp);
    for(int n=0;n<4;n++){
        if(num[n-1]-2==num[n]){   
                printf("%d""+2=""%d",num[n],num[n+1]);
                printf("\n");  
        }
        else{
            printf("%d",num[n]);
            printf(" ");
        }
    }
    return 0;
}