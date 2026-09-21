#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char test[81];
    scanf("%s",test);
    int len=strlen(test);
    int found=0;

    for(int i=0;i<len;i++){

        if(isupper(test[i])){
            found++;
        }

    }

    printf("%d\n",found);
    return 0;
}



//这个我没有写完，，现在时间是2025年11月20日
//之后回来接着写。