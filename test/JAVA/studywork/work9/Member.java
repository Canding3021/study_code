package JAVA.studywork.work9;

public class Member {
    private int Id;
    private String name;
    private int age;
    private String Grade;
    public Member(int ID,String name,int age,String Grade){
        Id=ID;
        this.name=name;
        this.age=age;
        this.Grade=Grade;
    }
    public int getAge() {
        return age;
    }
    public String getGrade() {
        return Grade;
    }
    public int getID() {
        return Id;
    }
    public String getName() {
        return name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setGrade(String grade) {
        Grade = grade;
    }
    public void setID(int iD) {
        Id = iD;
    }
    public void setName(String name) {
        this.name = name;
    }
    @Override
    public String toString(){
        return "详细信息{" +
                "成员编号：" + Id +
                ", 姓名：'" + name + '\'' +
                ", 年龄：" + age +
                ", 年级：'" + Grade + '\'' +
                '}';

    }
    public void remove(int memberID){

    }
}
