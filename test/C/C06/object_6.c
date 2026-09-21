/*   #include<stdio.h>
    #define MAX 100
    int main(){
        char str[MAX];
        int word,i;
        printf("enter a string.\n");
        //gets(str);
        if(str[0]!=" "){
            word=0;
        }else{
        if(str[i]!='\0'){
            word=1;
            i=1;
            while (str[i]!='\0')
            {
                if(str[i-1]==' '&&str[i]!=' '){
                    word++;
                }i++;
            }
        }
        printf("number fo string:%d\n",word);
        }
        return 0;
    }
    */