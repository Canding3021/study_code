#include<stdio.h>
int main(){
    int h,s;
    char im;
    int valid;
    scanf("%d %d %c %d",&h,&s,&im,&valid);
    for(int i=0;i<h;i++){
            if(valid==1){
                for(int n=0;n<s;n++){
                printf("%c",im);
                }  
                printf("\n");
            }
            /*else{
                for(int n=0;n<s;n++){
                if(i==0 || i==h-1 || n==0 || n==s-1 );
                    printf("%c",im);
                else(i==0 && i==h-1 && n==0 && n==s-1 );
                    printf(" ");
                
            } */     
             else {           // 空心
        for (int j = 0; j < s; j++) {
            if (i == 0 || i == h-1 || j == 0 || j == s-1)
                printf("%c", im);
            else
                printf(" ");
        }
            
            

            
        

    }





    return 0;
}


//心态真的崩了，尼玛的本来说是从19：20写道21：20结束的，现在都22：17了，不写了。算了吧，还在改代码，上来就是编译错误。。。。。。
//死了算了
