#include<stdio.h>
int Judgment(int num){
    int or_num=num;
    int back_num=0;
    while(num){
        back_num=back_num*10+num%10;
        num/=10;
    }
    if(or_num==back_num) return 1;
    else return 0;
}
int main(){
    int num;
    scanf("%d",&num);
    int number=0;
    for(int i=0;i<num;i++){
        if(Judgment(i)){
            number++;
        }
    }
    printf("%d",(number-1));
    return 0;
}