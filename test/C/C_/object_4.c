#include<stdio.h>
#include<stdlib.h>
typedef struct polynode{
    int data;
    struct polynode* next;
}PNode;
PNode * Creat_Link(int n){
    PNode *H,*s,*p;
    int data,i;
    H=(PNode*)malloc(sizeof(PNode));
    (*H).data=0;
    (*H).next=NULL;
    if(n<=0){
        return H;
    }
    p=H;
    for(i=0;i<n;i++){
        s=(PNode*)malloc(sizeof(PNode));
        printf("Please input any Continuous numbers:");
        scanf("%d",&data);
        (*s).data=data;
        (*s).next=NULL;
        (*p).next=s;
        p=s;
    }
    return H;
}
PNode * Insert_Link(PNode* H,int n){
    PNode *prev=H;
    PNode *curr=(*H).next;
    PNode *s;
    while(curr!=NULL && (*curr).data<n){
        prev=curr;
        curr=(*curr).next;
    }
    s=(PNode*)malloc(sizeof(PNode));
    (*s).data=n;
    (*s).next=curr;
    (*prev).next=s;
}
void Print_Link(PNode* H){
    PNode* p = H->next;
    if(p == NULL){
        printf("NULL\n");
        return;
    }
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    PNode* list;
    int n, x;
    printf("Please enter hao many coef you want to add:");
    scanf("%d", &n);
    list = Creat_Link(n);
    printf("The Link now:");
    Print_Link(list);
    printf("Please input the num you want to input:");
    scanf("%d", &x);
    printf("\n");
    Insert_Link(list, x);
    printf("The Link now\n");
    Print_Link(list);
    return 0;
}