#include<stdio.h>
#include<string.h>
int main(){
    int num;
    scanf("%d\n",&num);
    char zifu[100][11];
    int right=1;
   for(int i=0;i<num;i++){
    scanf("%s\n",zifu[i]);
   }
   for(int i=0;i<num && right==1;i++){
    for(int j=i+1;j<num;j++){
        if(strcmp(zifu[i],zifu[j])==0){
            right=0;
            break;
        }
    }
   }
   for(int i=1;i<num && right==1;i++){
    int len=(strlen(zifu[i-1]));
        if(zifu[i][0]!=zifu[i-1][len-1]){
            right=0;
            break;
        }
   }
   if(right==0){
    printf("No\n");
   }
   else{
    printf("Yes\n");
   }
    return 0;
}
