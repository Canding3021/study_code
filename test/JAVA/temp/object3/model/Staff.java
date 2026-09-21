package JAVA.temp.object3.model;

public class Staff {
    private int staffId;
    private String staffName;
    private double losttime;
    public Staff(){
        staffId=-1;
        staffName="NULL";
        losttime=0.00;
    }
    public Staff(int staffId,String staffName,double losttime){
        this.staffId=staffId;
        this.staffName=staffName;
        this.losttime=losttime;
    }
    public int getStaffId() {
        return staffId;
    }
    public void setStaffId(int staffId) {
        this.staffId = staffId;
    }
    public String getStaffName() {
        return staffName;
    }
    public void setStaffName(String staffName) {
        this.staffName = staffName;
    }
    public double getLosttime() {
        return losttime;
    }
    public void setLosttime(double losttime) {
        if(losttime<0){
            System.out.println("error input.");
        }else{
        this.losttime = losttime;
        }
    }
}
