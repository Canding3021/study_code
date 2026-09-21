package work5.homework.object1.model;
public class Car extends TrafficType{
    public Car(String trafficName,int wheelNumbers,String trafficColor,double trafficSpeed){
        super(trafficName,wheelNumbers,trafficColor,trafficSpeed);
    }
    @Override
    public void driving(){
        System.out.println(super.getWheelNumbers()+"个轮子的"+super.getTrafficColor()+"的"+super.getTrafficName()+"正在路上以"+super.getTrafficSpeed()+"km/h的速度行驶,能源来源为燃油燃烧");
    }
    public void addGasoline(){
        System.out.println(super.getTrafficName() + "正在加油...");
    }

}
