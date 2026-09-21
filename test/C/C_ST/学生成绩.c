#include<stdio.h>
int main(){

    int num_students,i;

    double score,sum=0,max_score=0,min_score=101;




    printf("请输入学生数：");
    scanf("%d",&num_students);



    for(i=0;i<num_students;i++){
        printf("请输入第""%d""个学生的成绩：",i+1);
        scanf("%lf",&score);



        sum+=score;



        if(score>max_score){
            max_score=score;
        }
        if(min_score>score){
            min_score=score;
        }




    }
     printf("\n成绩统计:\n");

    printf("总成绩：%.2lf\n", sum);

    printf("平均成绩：%.2lf\n", sum / num_students);

    printf("最高成绩：%.2lf\n", max_score);
    
    printf("最低成绩：%.2lf\n", min_score);

    return 0;
}