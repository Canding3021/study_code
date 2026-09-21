#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <locale.h>
struct Student {
   char name[99];
   int id;
   int age;
};
/*
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
*/
int cmp(const void*a,const void*b){
    return ((struct Student*)a)->age - ((struct Student*)b)->age;
}
int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    struct Student stu[3];
    int i;
    printf("|==========按照姓名、学号、年龄输入学生数据(空格隔开)=========|\n");
    printf("|==========      注意:只能输入至多三个学生数据       =========|\n");
    for(i=0;i<3;i++){
        scanf("%s %d %d",stu[i].name,&stu[i].id,&stu[i].age);
    }
    //qsort(n,num,sizeof(int),cmp);
    qsort(stu,3,sizeof(struct Student),cmp);
    printf("==========以下是按照年龄排序的学生的表格==========\n");
    for(i=0;i<3;i++){
         printf("姓名：%s\t学号:%d\t年龄:%.d\n", stu[i].name, stu[i].id, stu[i].age);
    }
    Sleep(30000);
    return 0;
}