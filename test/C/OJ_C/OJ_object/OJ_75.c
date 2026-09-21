#include<stdio.h>
#include<math.h>
int min(int x,int y){
    return (x<y)?x:y;
}
int main(){
    int num;
    scanf("%d",&num);
    int step1=0;
    int step2=0;
    int i=0;
    while(1){
        if(pow(2,i)>num){
            break;
        }
        i++;
    }
    step1=pow(2,i)-num;
    step2=num-pow(2,(i-1));
    int l=min(step1,step2);
    if(l==step2){
       printf("%d",(num-l));
    }
    else if(l==step1){
        printf("%d",(num+l));
    }
    return 0;
}