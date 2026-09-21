package JAVA.temp.object3.model;
import java.util.ArrayList;
import java.util.Scanner;

public class Project {
    public static void main(String[] args) {
        ArrayList<BaseStaff> baseStaffList = new ArrayList<>();
        ArrayList<TimeStaff> timeStaffList = new ArrayList<>();
        ArrayList<PerformanceStaff> perfStaffList = new ArrayList<>();
        
        boolean running = true;
        Scanner scanner=new Scanner(System.in);
        while (running) {
            System.out.println("\n----薪酬系统----");
            System.out.println("1.录入员工本月薪酬信息");
            System.out.println("2.工资明细查询");
            System.out.println("3.退出系统");
            System.out.print("请输入操作编号: ");
            
            int menuInput = scanner.nextInt();
        switch (menuInput) {
                case 1:
                    boolean keepEntering = true;
                    while (keepEntering) {
                        System.out.println("\n请输入员工薪资类别:");
                        System.out.print("1.固定工资制  2.时薪制  3.业绩制: ");
                        int type = scanner.nextInt();
                        
                        if (type != 1 && type != 2 && type != 3) {
                            System.out.println("输入错误，请重新输入。");
                            continue;
                        }
                        
                        System.out.print("请输入员工ID: ");
                        int id = scanner.nextInt();
                        System.out.print("请输入员工姓名: ");
                        String name = scanner.next();
                        System.out.print("请输入本月缺勤时长(小时): ");
                        double lostTime = scanner.nextDouble();
                        
                        switch (type) {
                            case 1:
                                System.out.print("请输入固定月薪: ");
                                double baseSalary = scanner.nextDouble();
                                baseStaffList.add(new BaseStaff(id, name, lostTime, baseSalary));
                                System.out.println("✓ 固定工资员工录入成功！");
                                break;
                                
                            case 2:
                                System.out.print("请输入时薪(元/小时): ");
                                double hourSalary = scanner.nextDouble();
                                System.out.print("请输入本月工作时长: ");
                                double hours = scanner.nextDouble();
                                timeStaffList.add(new TimeStaff(id, name, lostTime, hours, hourSalary));
                                System.out.println("✓ 时薪员工录入成功！");
                                break;
                                
                            case 3:
                                System.out.print("请输入底薪: ");
                                double perfBase = scanner.nextDouble();
                                System.out.print("请输入本月销售额: ");
                                double sales = scanner.nextDouble();
                                perfStaffList.add(new PerformanceStaff(id, name, lostTime, sales, perfBase));
                                System.out.println("✓ 绩效员工录入成功！");
                                break;
                        }
                        
                        // 问是否继续
                        System.out.print("\n是否继续录入员工信息?(1.是  2.否): ");
                        int choice = scanner.nextInt();
                        if (choice == 2) {
                            keepEntering = false;
                        }
                    }
                    break;
            case 2:
             int totalStaff = baseStaffList.size() + timeStaffList.size() + perfStaffList.size();
                    
                    if (totalStaff == 0) {
                        System.out.println("\n暂无员工数据,请先录入。");
                    } else {
                        System.out.println("\n========== 工资明细 ==========");
                        
                        if (!baseStaffList.isEmpty()) {
                            System.out.println("\n【固定工资员工】");
                            for (BaseStaff bs : baseStaffList) {
                                System.out.printf("  %s (ID:%d) 应发: %.2f 元\n",
                                    bs.getStaffName(), bs.getStaffId(), bs.calculateSalary());
                            }
                        }
                        
                        if (!timeStaffList.isEmpty()) {
                            System.out.println("\n【时薪员工】");
                            for (TimeStaff ts : timeStaffList) {
                                System.out.printf("  %s (ID:%d) 应发: %.2f 元\n",
                                    ts.getStaffName(), ts.getStaffId(), ts.calculateSalary());
                            }
                        }
                        
                        if (!perfStaffList.isEmpty()) {
                            System.out.println("\n【绩效员工】");
                            for (PerformanceStaff ps : perfStaffList) {
                                System.out.printf("  %s (ID:%d) 应发: %.2f 元\n",
                                    ps.getStaffName(), ps.getStaffId(), ps.calculateSalary());
                            }
                        }
                        
                        System.out.println("\n==============================");
                    }
                    break;
            case 3:
                System.out.println("感谢您的使用.");
                running=false;
                break;
            default:
                break;
        }
        }
        scanner.close();
    }
    
}
