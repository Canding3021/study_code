package JAVA.temp.object3.model;

public class TimeStaff extends Staff implements Payable{
    private double workingHours;
    private double moneyForHours;
    public TimeStaff(int staffId,String staffName,double losttime,double workinghours,double moneyForHours){
        super(staffId,staffName,losttime);
        this.workingHours=workinghours;
        this.moneyForHours=moneyForHours;
    }
    public void setWorkinghours(double workinghours) {
        if(workinghours<=120){
            System.out.println("low hours.");
        }else{
        this.workingHours = workinghours;
        }
    }
    public double getWorkinghours() {
        return workingHours;
    }
    public void setMoneyForHours(double moneyForHours) {
        if(moneyForHours>=0){
            this.moneyForHours = moneyForHours;
        }else{
            System.out.println("error input.");
            moneyForHours=0.00;
        }
    }
    public double getMoneyForHours() {
        return moneyForHours;
    }
    @Override
    public double calculateSalary() {
        // TODO Auto-generated method stub
        return workingHours*moneyForHours-getLosttime()*50;
    }
    public void addstaff(){
        System.out.println("请输入员工ID:");
    }
}
