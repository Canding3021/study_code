package JAVA.temp.object3.model;

public class BaseStaff extends Staff implements Payable{
    private double baseSalary;
    public BaseStaff(int staffId,String staffName,double losttime,double baseSalary){
        super(staffId,staffName,losttime);
        this.baseSalary=baseSalary;
    }
    public double getBaseSalary() {
        return baseSalary;
    }
    public void setBaseSalary(double baseSalary) {
        if (baseSalary>=0) {
            this.baseSalary = baseSalary;
        }else{
            System.out.println("error enter.");
            baseSalary=0.00;
        }
        
    }
    @Override
    public double calculateSalary() {
        // TODO Auto-generated method stub
        return baseSalary-getLosttime()*50;
    }
}
