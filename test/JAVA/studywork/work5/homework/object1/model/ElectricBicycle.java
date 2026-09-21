package work5.homework.object1.model;
public class ElectricBicycle extends TrafficType{
    public ElectricBicycle(String trafficName,int wheelNumbers,String trafficColor,double trafficSpeed){
        super(trafficName,wheelNumbers,trafficColor,trafficSpeed);
    }
    @Override
    public void driving(){
        System.out.println(super.getWheelNumbers()+"个轮子的"+super.getTrafficColor()+"的"+super.getTrafficName()+"正在路上以"+super.getTrafficSpeed()+"km/h的速度行驶,能源来源为动力电池");
    }
    public void charge(){
	    System.out.println(super.getTrafficName() + "充电中...");
	}

}
