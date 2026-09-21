#include<stdio.h>
#include<math.h>    
int main(){
    for(int i=100;i<1000;i++){
        int or_num=i;
        int num1,num2,num3;
        num1=i%10;
        num2=(i/10)%10;
        num3=i/100;
        if(pow(num1,3)+pow(num2,3)+pow(num3,3)==or_num){
            printf("%d\n",or_num);  
        }
    }
    return 0;
}