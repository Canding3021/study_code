#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#define MAXSIZE 100
//SqList 是 Sequential List 的缩写，通常用于表示线性表的顺序存储结构。
typedef struct{
    int data[MAXSIZE];
    int length;
}Sqlist;
//同一种类型的表只需要定义一次
int isPrime(int n){
    if(n<=1){
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int Fib(int n){
    int t1=0,t2=1,nextTerm;
    if(n==1)return 0;
    if(n==2)return 1;
    for(int i=3;i<=n;i++){
        nextTerm=t1+t2;
        t1=t2;
        t2=nextTerm;
    }
    return t2;
}
int findList(Sqlist L,int x){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==x){
            return 1;
        }
    }
    return 0;
}
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int main(){
    setlocale(LC_ALL, "en_US.UTF-8");
    printf("25软件技术_250322226_李哲煜\n");
    Sqlist A;
    Sqlist B;
    A.length=0;
    B.length=0;
    printf("========正在往表A、表B写入数据......========\n");
    printf("|表A为100以内的素数,表B为100以内的斐波那契数列|\n");
    for(int i=2;i<100;i++){
        if(isPrime(i)){
            A.data[A.length]=i;
            A.length++;
        }
    }
    int i=2;
    while(1){
        int Fib_back_num=Fib(i);
        if(Fib_back_num>100) break;
        B.data[B.length]=Fib_back_num;
        B.length++;
        i++;
    }
    printf("\n===== 表A(100以内素数)=====\n");
    for(int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
    printf("\n共%d个素数\n", A.length);
    printf("\n===== 表B(100以内斐波那契数)=====\n");
    for(int i = 0; i < B.length; i++) {
        printf("%d ", B.data[i]);
    }
    printf("\n共%d个斐波那契数\n", B.length);
    printf("\n========正在将线性表B合并至线性表A......========\n");
    for(int i=0;i<B.length;i++){
        int num=B.data[i];
        if(!findList(A,num)){
            A.data[A.length]=num;
            A.length++;
            printf("添加 %d 到A表\n",num);
        }
        else{
            printf("%d 已在A表中,跳过\n", num);
        }
    }
    printf("\n===== 合并后的A表 =====\n");
    for(int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
        if((i + 1) % 10 == 0) printf("\n");
    }
    qsort(A.data,A.length,sizeof(int),cmp);
    printf("\n===== 整理后的A表 =====\n");
    for(int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
        if((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n共%d个元素\n", A.length);
    printf("press any key to exit.....\n");
    getch();
    return 0;
}
