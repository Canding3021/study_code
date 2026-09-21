/*#include<stdio.h>
int main(){
    int num;
    printf("请输入输出个数(>=2):");
    scanf("%d",&num);
    int i=2;
    int num1=1;
    int num2=1;
    if(num<2){
        printf("输入数字不合法。");
        return 0;
    }
    while(1){
        printf("1,1");
        num1+=num2+num1;
        printf("%d",num1);
        num2+=num2+num1;
        printf("%d",num2);
        i+=2;
        if(i>num){
            break;
        }
    }
    return 0;
}
*/
#include<stdio.h>
int main(){
    int a,b;
    printf("%d",(a=2)&&(b=-2));
    return 0;
}