#include<stdio.h>
int main(){
    int hang;
    scanf("%d",&hang);
    long long num[100];
    for(int i=0;i<hang;i++){
        scanf("%d\n",&num[i]);
    }
    int min=1;
    while(1){
        int i=0;
        if(min%num[i]==0 && min%num[i+1]==0){
            break;
        }
        else{
            i++;
        }
    }
    printf("%d",min);
    return 0;
}

//草泥马，被ai说我写的代码依托狗屎。。。。不
//不想活了，不写了，尼玛的
//我这写的是什么狗屎啊？？？？
//但是你别说，这个还算是一点进步哈哈.