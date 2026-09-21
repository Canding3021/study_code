#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int num[a];
    for(int i=0;i<a;i++){
        scanf("%d",&num[i]);
    } 
    for(int n=a-1;n>=0;n--){
         printf("%d",num[n]);
         if(n>0)printf(" ");
    }
    return 0;
}