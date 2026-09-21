/*#include<stdio.h>
#include<math.h>
int main(){
    long long num,or_num;
    scanf("%lld",&num);
    or_num=num;
    int l=0;
    while(1){
        if(num==0){
            break;
        }
        else{
            num/=10;
            l++;
        }
    }
    int n[l];
    int i=0;
    while(1){
        n[i]=num%10;
        num/=10;
        i++;
        if(num==0){
            break;
        }
    }
    int sum=0;
    for(int i=l;i>0;i--){
        for(int h=0;h<i;h++){
            sum+=n[h]*(int)pow(10,i-1);
        }
    }
    printf("%d\n",sum);
    return 0;
}
    */
   #include <stdio.h>

int main() {
    long long num, reversed = 0;
    scanf("%lld", &num);

    while (num > 0) {
        // 提取最后一位数字并加入反转结果
        reversed = reversed * 10 + num % 10;
        // 去掉最后一位数字
        num /= 10;
    }

    printf("%lld\n", reversed);
    return 0;
}



//很经典的倒数环节，太帅了