#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return *(int*)b-*(int*)a;
}
int main(){
    int num[3];
    for(int i=0;i<3;i++){
        scanf("%d",&num[i]);
    }
    qsort(num,3,sizeof(int),cmp);
    for(int n=0;n<3;n++){
        printf("%d",num[n]);
        printf(" ");
    }
    return 0;
}