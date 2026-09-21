package JAVA.studywork.work9;
import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class ClubMembersManage {
    private static List<Member> members =new ArrayList<>();
    static Scanner sc =new Scanner(System.in);
    public static void addMember(){
        boolean isExist =false;
        System.out.println("请输入成员的编号、姓名、年龄和年级：");
        do{
            int MemberID=sc.nextInt();
            String MemberName=sc.next();
            int MemberAge=sc.nextInt();
            String MemberGader=sc.next();
            for(Member member:members){
                if(member.getID()==MemberID){
                    isExist=true;
                }
            }
            if (!isExist) {
                Member member=new Member(MemberID, MemberName, MemberAge, MemberGader);
                members.add(member);
                System.out.println("成功添加成员:" + member);
            }else{
                System.out.print("成员编号已存在，请选择其他编号并重新输入:");
            }
        }while(isExist);
    }
    public static void updataMember(){
        System.out.println("请输入成员的编号:");
        int MemberID=sc.nextInt();
        System.out.println("请输入新的年龄和班级:");
        int age=sc.nextInt();
        String Grade=sc.next();
        for(Member member:members){
            if(member.getID()==MemberID){
                member.setAge(age);
                member.setGrade(Grade);
                System.out.println("成功添加成员:" + member);
                return;
            }
        }
        System.out.println("成员编号输入错误！：" + MemberID);
    }
    public static void searchMemberByGrade(){
        List<Member> foundMembers = new ArrayList<>();
        System.out.println("请输入年级:");
        String Grade=sc.next();
        for(Member member: members){
            if(member.getGrade().equals(Grade)){
                foundMembers.add(member);
                selectALL(foundMembers);
            }
        }
        if(!foundMembers.isEmpty()){
            System.out.println(Grade + "的成员信息如下------");
            
        }else{
            System.out.println("社团中没有" + Grade + "的成员！");
        }
    }
    public static void selectALL(List<Member> members){
        System.out.println("成员编号  姓名   年龄  年级  ");
        for(Member member:members){
            System.out.println("   " + member.getID() + "     ");
            System.out.println(member.getName() + "   ");
            System.out.println(member.getAge() + "岁   ");
            System.out.println(member.getGrade());
        }
    }
    public static void deleteMember(){
        System.out.println("请输入成员编号:");
        int memberID = sc.nextInt();
        for(Member member:members){
            if(member.getID()==memberID){
                members.remove(member);
                System.out.println("成功删除成员:"+member);
                return;
            }
        }
        System.out.println("找不到指定编号的成员：" + memberID);
    }
    public static void displayAllMembers() {
        if (members.isEmpty()) {
            System.out.println("目前社团没有任何成员！");
        }else{
            System.out.println("----------社团所有成员----------");
            selectALL(members);
        }
    }
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("--------书法社团成员管理系统--------");
    System.out.println("1. 查看目前社团所有成员");
    System.out.println("2. 添加社团成员");
    System.out.println("3. 修改成员信息");
    System.out.println("4. 查看指定年级的成员");
    System.out.println("5. 移除成员");
    System.out.println("6. 退出系统");
    while (true){
        System.out.print("请输入要进行的操作：");
        int option = sc.nextInt();
        switch (option){
            case 1:
                displayAllMembers();
                break;
            case 2:
                addMember();
                break;
            case 3:
                updataMember();
                break;
            case 4:
                searchMemberByGrade();
                break;
            case 5:
                deleteMember();
                break;
            case 6:
                sc.close();
                System.out.println("退出系统...");
                System.exit(0);
        }
    }
}

}
