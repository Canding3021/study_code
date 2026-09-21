package work4.homeWork.homework3.control;
import work4.homeWork.homework3.model.Student;
public class StudentScoreManager {
    public static Student[] students;
    public static void InitStudents(){
        students=new Student[5];
        students[0] = new Student("小明", 1, 97, 70, 89, 68, 78);
        students[1] = new Student("小红", 2, 95, 92, 88, 85, 90);
        students[2] = new Student("小刚", 3, 78, 82, 75, 70, 68);
        students[3] = new Student("李华", 4, 85, 88, 92, 79, 84);
        students[4] = new Student("小美", 5, 98, 95, 96, 94, 97);
    }
    public static double sumStudents(){
        double sumScore=0;
        for(int i=0;i<students.length;i++){
            sumScore+=students[i].getSumScore();
        }
        return sumScore;
    }
    public static double averageScore(){
        double sumScore=0;
        double validScore=0;
        for(int i=0;i<students.length;i++){
            sumScore+=students[i].getSumScore();
        }
        validScore=sumScore/students.length;
        return validScore;
    }
    public static void displayStatistics() {
    double totalScore = 0;
    double totalMath = 0, totalChinese = 0, totalEnglish = 0, totalPhysics = 0, totalChemistry = 0;
    int validCount = 0;
    for (int i = 0; i < students.length; i++) {
        if (students[i] != null) {
            totalMath += students[i].getMathScore();
            totalChinese += students[i].getChineseScore();
            totalEnglish += students[i].getEnglishScore();
            totalPhysics += students[i].getPhysicsScore();
            totalChemistry += students[i].getChemistryScore();
            totalScore += students[i].getSumScore();
            validCount++;
        }
    }
    double averageMath = totalMath / validCount;
    double averageChinese = totalChinese / validCount;
    double averageEnglish = totalEnglish / validCount;
    double averagePhysics = totalPhysics / validCount;
    double averageChemistry = totalChemistry / validCount;
    double averageScore = totalScore / validCount;
    System.out.println("\n========== 班级成绩统计 ==========");
    System.out.println("学生人数: " + validCount);
    System.out.println();
    System.out.println("--- 各科总分 ---");
    System.out.printf("数学总分: %.2f%n", totalMath);
    System.out.printf("语文总分: %.2f%n", totalChinese);
    System.out.printf("英语总分: %.2f%n", totalEnglish);
    System.out.printf("物理总分: %.2f%n", totalPhysics);
    System.out.printf("化学总分: %.2f%n", totalChemistry);
    System.out.println();
    System.out.println("--- 各科平均分 ---");
    System.out.printf("数学平均分: %.2f%n", averageMath);
    System.out.printf("语文平均分: %.2f%n", averageChinese);
    System.out.printf("英语平均分: %.2f%n", averageEnglish);
    System.out.printf("物理平均分: %.2f%n", averagePhysics);
    System.out.printf("化学平均分: %.2f%n", averageChemistry);
    System.out.println();
    System.out.println("--- 总体统计 ---");
    System.out.printf("班级总分: %.2f%n", totalScore);
    System.out.printf("班级平均分: %.2f%n", averageScore);
    System.out.println("==================================");
}
    
}
