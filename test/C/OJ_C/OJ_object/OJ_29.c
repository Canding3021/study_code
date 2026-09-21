//尼玛的，这个问题就是待续一个四位数，，只有数学上的优化，没有实则代码方面的创新啊。。。。
#include<stdio.h>
#include<math.h>
int main(){
    int num;
    scanf("%d",&num);
    int ge=num%10;
    int shi=(num/10)%10;
    int bai=(num/100)%10;
    int qian=num/1000;
    int an=ge*1000+shi*100+bai*10+qian;
    printf("%d\n",an);



    return 0;
}