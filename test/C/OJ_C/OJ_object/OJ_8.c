#include<stdio.h>
int main(){
    int hang;
    scanf("%d",&hang);
    for(int i=0;i<hang;i++){
        for(int n=0;n<=(hang-i-2);n++){
             printf(" ");
        }
        for(int l=1;l<=(i*2+1);l++){
            printf("%d",(i+1));

        }
        printf("\n");
    }
    return 0;
}