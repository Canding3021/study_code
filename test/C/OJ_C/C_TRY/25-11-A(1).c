#include<stdio.h>
int main(){
    int num1;
    int num2;
    scanf("%d %d",&num1,&num2);
    if(num1<=9 && num1>=1 && num2<=9 && num2>=1){
        int an=num1*num2;
        printf("%d\n",an);
    }
    else{
        printf("-1\n");
    }    
        return 0;
}