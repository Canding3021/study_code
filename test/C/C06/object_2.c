#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return *(int*)b-*(int*)a;
}
int main(){
    int list[10];
    printf("input the number:\n");
    for(int i=0;i<10;i++){
        scanf("%d",&list[i]);
    }
    qsort(list,10,sizeof(int),cmp);
    printf("The max number is:%d",list[0]);
    return 0;
}
/*
int max=0;
for(int i=0;i<n;i++){
    printf("...");
    scanf("%d",&input);
    
}
*/


