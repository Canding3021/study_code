#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct polynode{
    int coef,exp;
    struct polynode* next;
}PNode;
PNode * Creat_link(int n){
    PNode *head,*s,*p;
    int i;
    head=(PNode*)malloc(sizeof(PNode));
    (*head).next=NULL;
    p=head;
    printf("enter coef,exp(separated by space):\n");
    for(i=0;i<n;i++){
        s=(PNode*)malloc(sizeof(PNode));
        scanf("%d %d",&(*s).coef,&(*s).exp);
        (*s).next=NULL;
        (*p).next=s;
        p=s;
    }
    return(head);
}
void Print_Link(PNode* H){
    PNode* p;
    p=(*H).next;
    if(p == NULL){
        printf("empty polynode.\n");
        return;
    }
    while ((*p).next)
    {
        printf("%dx^%d+",(*p).coef,(*p).exp);
        p=(*p).next;
    }
    if((*p).exp!=0){
        printf("%dx^%d\n",(*p).coef,(*p).exp);
    }else   printf("%d\n",(*p).coef);
}
int deleteData(PNode* H,int coef,int exp){
    PNode* p;
    PNode* c;
    p=H;
    c=(*H).next;
    while (c)
    {
        if((*c).coef==coef&&(*c).exp==exp){
            (*p).next=(*c).next;
            free(c);
            printf("delete the coef and exp.\n");
            return 1;
        }
        p=c;
        c=(*c).next;
    }
    printf("Can't find the coef and exp.\n");
    return 0;
}
int main(){
    PNode* list = Creat_link(3);  
    Print_Link(list); 
    deleteData(list,3,5);
    Print_Link(list);
    Sleep(3000);             
    return 0;
}