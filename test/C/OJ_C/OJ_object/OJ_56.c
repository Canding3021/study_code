#include<stdio.h>
int main(){
    int sum=0;
    for(int i=0;i<1000;i++){
        int temp = i;
        while (temp > 0) {
            if (temp % 10 == 3) {
                sum++;
                break; 
            }
            temp /= 10;
        }
    }   
    printf("%d",sum);    
    return 0;
}