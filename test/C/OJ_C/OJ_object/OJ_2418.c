#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int main(){
    int num;
    scanf("%d",&num);
    int n[num];
    for(int i=0;i<num;i++){
        scanf("%d",&n[i]);
    }
    qsort(n,num,sizeof(int),cmp);
    int l=0;
    for(int i=0;i<num;i++){
        if(n[i]==n[i+1]){
            l++;
        }
    }
    printf("%d",l);
    return 0;
}