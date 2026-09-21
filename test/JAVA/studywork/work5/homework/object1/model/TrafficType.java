package work5.homework.object1.model;
public class TrafficType {
    private String trafficName;
    private int wheelNumbers;
    private String trafficColor;
    private double trafficSpeed;
    public TrafficType() {
        this.trafficName = "NULL";
        this.wheelNumbers = 0;
        this.trafficColor = "NULL";
        this.trafficSpeed = 0;
    }
    public TrafficType(String trafficName,int wheelNumbers,String trafficColor,double trafficSpeed){
        this.trafficName=trafficName;
        this.wheelNumbers=wheelNumbers;
        this.trafficColor=trafficColor;
        this.trafficSpeed=trafficSpeed;
    }
    public void setTrafficName(String trafficName) {
        this.trafficName = trafficName;
    }
    public String getTrafficName() {
        return trafficName;
    }
    public void setWheelNumbers(int wheelNumbers) {
        this.wheelNumbers = wheelNumbers;
    }
    public int getWheelNumbers() {
        return wheelNumbers;
    }
    public void setTrafficColor(String trafficColor) {
        this.trafficColor = trafficColor;
    }
    public String getTrafficColor() {
        return trafficColor;
    }
    public void setTrafficSpeed(double trafficSpeed) {
        this.trafficSpeed = trafficSpeed;
    }
    public double getTrafficSpeed() {
        return trafficSpeed;
    }
    public void driving(){
        System.out.println(wheelNumbers+"个轮子的"+trafficColor+"的"+trafficName+"正在路上以"+trafficSpeed+"km/h的速度行驶");
    }
    public void speedUp(int increase){
        trafficSpeed+=increase;
        System.out.println("正在加速，当前速度: " + trafficSpeed + " km/h");
    }
    public void speedDown(int decrease){
        trafficSpeed-=decrease;
        System.out.println("正在减速，当前速度: " + trafficSpeed + " km/h");
    }
}
