#include<stdio.h>
int main(){
    for(int i=1;i<1000;i++){
        if(i%3==0){
            int temp=i;
            while(temp>0){
                if(temp%10==5){
                    printf("%d\n",i);
                    break;
                }
                temp/=10;
            }
        }
    }
    return 0;
}