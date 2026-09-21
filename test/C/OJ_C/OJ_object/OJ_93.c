#include<stdio.h>
int main(){
    for(char i='a';i<='m';i++){
        printf("%c",i);
    }
     for (char i = 'n'; i <= 'z'; i++) {
        printf("%c", i);  
    }
    printf("\n");

    
    for (char i = 'z'; i >= 'n'; i--) {
        printf("%c", i);  
    }
    printf("\n");

    for (char i = 'm'; i >= 'a'; i--) {
        printf("%c", i);  
    }
    printf("\n");
    return 0;
}