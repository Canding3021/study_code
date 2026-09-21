#include<stdio.h>
int main(){
    int innum1,innum2;
    scanf("%d %d",&innum1,&innum2);
    if(innum1%innum2==0){
        int outnum=innum1/innum2;
        printf("%d",outnum);
    }
    else if(innum1%innum2!=0){
        int outnum=innum1/innum2+1;
        printf("%d",outnum);
    }

    return 0;
}