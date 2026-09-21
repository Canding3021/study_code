#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int back=0;
    if(num>=86){
        back=1;
    }
    else if(num<=85 && num>=60){
        back=2;
    }
    else if(num<60){
        back=3;
    }else{ 
        printf("error input");
        return 1;
    }
    switch (back){
    case 1:
        printf("VERY GOOD");
        break;
    case 2:
        printf("GOOD");
        break;
    case 3:
        printf("BAD");
        break;
    default:
        return -1;
    }
    return 0;
}
//2026/3/23

