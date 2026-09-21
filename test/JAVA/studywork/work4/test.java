package work4;
public class test {
public static class Student {
    String name;
    int classId;
    int StudentId;
    String address;
    public void introduce(){
        System.out.println("大家好，我是"+name+"来自于"+classId+"班。"+"我的学号是"+StudentId+",来自"+address+"。");
    }
    public void study(){
        System.out.println("我要开始学习了!");
    }
}
    public static void main(String[] args){
        Student student1 = new Student();
        student1.name="小明";
        student1.classId=1;
        student1.StudentId=1;
        student1.address="北京";
        student1.introduce();
        student1.study();
    }
}
