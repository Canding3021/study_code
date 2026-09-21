package work5.homework.object1.project;
import work5.homework.object1.model.Car;
import work5.homework.object1.model.Bicycle;
import work5.homework.object1.model.ElectricBicycle;;
public class Traffictext {
    public static void main(String[] args) {
        System.out.println("创建一个自行车对象");
        Bicycle b  = new Bicycle("自行车",2,"黑色",15);
        b.driving();
        b.speedUp(3);
        b.speedDown(2);
        System.out.println("创建一个电动车对象");
        ElectricBicycle eb = new ElectricBicycle("电动车",2,"蓝色",25);
        eb.charge();
        eb.driving();
        eb.speedUp(7);
        eb.speedDown(10);
        System.out.println("创建一个小汽车对象");         
        Car car = new Car("小汽车",4,"白色",40);
        car.addGasoline();
        car.driving();
        car.speedUp(30);
        car.speedDown(10);

    }
}
