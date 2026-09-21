package work3;
import java.util.Scanner;

public class work2 {
    // 属性
    private String[] name;
    private int[][] grade;
    private String[] subjects = {"C程序设计", "物理", "英语", "高数", "体育", "政治"};
    public work2() {
        name = new String[]{ "lili", "tom", "jack", "susan", "wendy", 
                            "tommy", "neil", "paul", "richie", "roger" };
        grade = new int[][]{
            { 50, 60, 70, 80, 90, 10 },
            { 40, 90, 80, 60, 40, 70 },
            { 60, 80, 70, 60, 40, 90 },
            { 50, 60, 70, 80, 90, 10 },
            { 60, 80, 70, 60, 40, 90 },
            { 60, 70, 80, 90, 70, 70 },
            { 60, 80, 70, 60, 40, 90 },
            { 60, 80, 70, 60, 40, 90 },
            { 70, 80, 90, 70, 70, 70 },
            { 60, 80, 70, 60, 40, 90 }
        };
    }
    public void queryStudentScore(String studentName) {
        for (int i = 0; i < name.length; i++) {
            if (name[i].equals(studentName)) {
                System.out.println("学生：" + name[i] + " 的成绩如下：");
                System.out.println("C程序设计:" + grade[i][0] + 
                                 " 物理：" + grade[i][1] + 
                                 " 英语：" + grade[i][2] + 
                                 " 高数：" + grade[i][3] + 
                                 " 体育：" + grade[i][4] + 
                                 " 政治：" + grade[i][5]);
                return;
            }
        }
        System.out.println("没有找到学生：" + studentName);
    }
    public void queryFailedStudents(int subjectIndex) {
        int subjectPos = subjectIndex - 1;  
        int failCount = 0;
        
        System.out.println(subjects[subjectPos] + "不及格的名单为：");
        
        for (int i = 0; i < name.length; i++) {
            if (grade[i][subjectPos] < 60) {
                System.out.println(name[i] + ":" + grade[i][subjectPos] + "分");
                failCount++;
            }
        }
        
        System.out.println("该科目不及格人数为：" + failCount);
    }
    
    public void calculateSubjectStats(int subjectIndex) {
        int subjectPos = subjectIndex - 1;  
        int sum = 0;
        int max = grade[0][subjectPos];  
        for (int i = 0; i < name.length; i++) {
            int score = grade[i][subjectPos];
            sum += score;
            if (score > max) {
                max = score;
            }
        }
        double average = (double)sum / name.length;
        System.out.println("\n=== " + subjects[subjectPos] + " 成绩统计 ===");
        System.out.println("平均分：" + String.format("%.1f", average));
        System.out.println("最高分：" + max);
        System.out.print("考" + max + "分的同学有：");
        for (int i = 0; i < name.length; i++) {
            if (grade[i][subjectPos] == max) {
                System.out.print(name[i] + " ");
            }
        }
        System.out.println();
    }
    public void showMenu() {
        System.out.println("\n科目列表:");
        for (int i = 0; i < subjects.length; i++) {
            System.out.println((i + 1) + "." + subjects[i]);
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Scanner choice=new Scanner(System.in);
        work2 work2 = new work2();
        byte booler=0;
        byte choose=0;
        do{
        System.out.println("请输入要进行的操作:\n1.查询学生成绩\n2.查询科目不及格人数\n3.查询科目平均分和最高分\n4.退出");
        choose=choice.nextByte();
        switch (choose){
            case 1: 
                System.out.println("输入要查询成绩的学生名字：");
                String name = input.nextLine();
                work2.queryStudentScore(name);
                break;
            case 2:
                work2.showMenu();
                System.out.println("\n输入要查询不及格人数的科目序号:");
                int ch1 = input.nextInt();
                work2.queryFailedStudents(ch1);
                break;
            case 3:
                work2.showMenu();
                System.out.println("\n输入要计算平均分和最高分的科目序号:");
                int ch2 = input.nextInt();
                work2.calculateSubjectStats(ch2);
                break;
            case 4:
                booler++;
                break;
            }
        }while(booler==0);
        input.close();

        
        choice.close();
    }    
}
