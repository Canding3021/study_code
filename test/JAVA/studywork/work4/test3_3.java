package work4;

class Staff {
    String name;
    int salary;
}
public class test3_3 {
    public static void modifySalary(int salary){
        salary+=1000;
    }
    public static void modifySalary(Staff staff){
        staff.salary+=1000;
    }
    public static void main(String[] args){
        Staff staff=new Staff();
        staff.name="小明";
        staff.salary=5000;
        System.out.println(staff.name+"原本的薪水"+staff.salary+"￥");
        modifySalary(staff.salary);
        System.out.println("值传递薪水："+staff.salary);
        modifySalary(staff);
        System.out.println("引用传递加薪："+staff.salary);
    }
}