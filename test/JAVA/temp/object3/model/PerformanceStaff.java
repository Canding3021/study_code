package JAVA.temp.object3.model;

public class PerformanceStaff extends Staff implements Payable{
    private double totalSales;
    private double baseSalary;
    public PerformanceStaff(int staffId,String staffName,double losttime,double totalSales,double baseSalary){
        super(staffId,staffName,losttime);
        this.totalSales=totalSales;
        this.baseSalary=baseSalary;
    }
    public double getTotalSales() {
        return totalSales;
    }
    public void setTotalSales(double totalSales) {
        if(totalSales>=0){
            this.totalSales = totalSales;
        }else{
            System.out.println("error input.");
            totalSales=0.00;
        }
    }
    public void setBaseSalary(double baseSalary) {
        if(baseSalary>0){
            this.baseSalary = baseSalary;   
        }else{
            System.out.println("error input.");
            baseSalary=0.00;
        }

    }
    public double getBaseSalary() {
        return baseSalary;
    }
    @Override
    public double calculateSalary() {
        // TODO Auto-generated method stub
        if(totalSales>=0 && totalSales<=5000){
            return (double)((baseSalary*1.00+totalSales*0.12)-getLosttime()*50);
        }else if (totalSales>=5000 && totalSales<=10000) {
            return (double)((baseSalary*1.00+5000*0.12+(totalSales-5000)*0.15)-getLosttime()*50);
        }else{
            return (double)((baseSalary*1.00+5000*0.12+5000*0.15+(totalSales-10000)*0.18)-getLosttime()*50);
        }
    }
}
