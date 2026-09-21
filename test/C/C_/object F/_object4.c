#include<stdio.h>
#include<stdlib.h>
typedef struct polynode{
    int data;
    struct polynode* prior;
    struct polynode* next;
}PNode;
PNode * Creat_link(int n){
    PNode *H,*s,*p;
    int i,data;
    H=(PNode*)malloc(sizeof(PNode));
    (*H).prior=H; 
    (*H).next=H;
    (*H).data=0;
    if(n<=0){
        return H;
    }
    p=H;
    for(i=0;i<n;i++){
        s=(PNode*)malloc(sizeof(PNode));
        data=i+1;
        (*s).data=data;
        (*s).prior=p;
        (*s).next=H;
        (*p).next=s;
        (*H).prior=s;
        p=s;
    }
    return H;
}

//尼玛的，这个作业要求写单链，死！