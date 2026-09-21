package work4.homeWork.homework3.model;
public class Student {
    private String studentName;
    private int studentId;
    private double mathScore;
    private double chineseScore;
    private double englishScore;
    private double physicsScore;
    private double chemistryScore;
    private double sumScore;
    public Student(String studentName, int studentId, 
                   double mathScore, double chineseScore, 
                   double englishScore, double physicsScore, 
                   double chemistryScore) {
        setStudentName(studentName);
        setStudentId(studentId);
        setMathScore(mathScore);
        setChineseScore(chineseScore);
        setEnglishScore(englishScore);
        setPhysicsScore(physicsScore);
        setChemistryScore(chemistryScore);
    }
    public void setStudentName(String studentName) {
        this.studentName = studentName;
    }
    public String getStudentName() {
        return studentName;
    }
    public void setStudentId(int studentId) {
        if(studentId<=0){
            System.out.println("error id.");
            this.studentId=1;
        }else{
        this.studentId = studentId;
        }
    }
    public int getStudentId() {
        return studentId;
    }
    public void setMathScore(double mathScore) {
        if(mathScore<0){
            System.out.println("error score.");
            this.mathScore=0;
        }else{
        this.mathScore = mathScore;
        }
    }
    public double getMathScore() {
        return mathScore;
    }
    public void setChineseScore(double chineseScore) {
        if(chineseScore<0){
            System.out.println("error score.");
            this.chineseScore=0;
        }else{
        this.chineseScore = chineseScore;
        }
    }
    public double getChineseScore() {
        return chineseScore;
    }
    public void setEnglishScore(double englishScore) {
        if(englishScore<0){
            System.out.println("error score.");
            this.englishScore=0;
        }else{
        this.englishScore = englishScore;
        }
    }
    public double getEnglishScore() {
        return englishScore;
    }
    public void setPhysicsScore(double physicsScore) {
        if(physicsScore<0){
            System.out.println("error score.");
            this.physicsScore=0;
        }else{
        this.physicsScore = physicsScore;
        }
    }
    public double getPhysicsScore() {
        return physicsScore;
    }
    public void setChemistryScore(double chemistryScore) {
        if(chemistryScore<0){
            System.out.println("error score.");
            this.chemistryScore=0;
        }else{
        this.chemistryScore = chemistryScore;
        }
    }
    public double getChemistryScore() {
        return chemistryScore;
    }
    public double getSumScore(){
        sumScore=mathScore+chineseScore+englishScore+physicsScore+chemistryScore;
        return sumScore;
    }
    public void studentInfo(){
        System.out.println("学生姓名:" + studentName);
        System.out.println("学生ID:" + studentId);
        System.out.println("数学成绩:" + mathScore);
        System.out.println("语文成绩:" + chineseScore);
        System.out.println("英语成绩:" + englishScore);
        System.out.println("物理成绩:" + physicsScore);
        System.out.println("化学成绩:" + chemistryScore);
    }
}
