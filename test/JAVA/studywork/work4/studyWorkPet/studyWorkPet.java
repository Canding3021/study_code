package work4.studyWorkPet;
import java.util.Scanner;

class pet{
    private String petType;
    private double petAge;
    private byte vaccinum;
    public pet(String petType,double petAge,byte vaccinum){
        this.petType=petType;
        if(petAge>=0){
            this.petAge=petAge;
        }else{
            System.out.println("Age error.");
            this.petAge=0;
        }
        if(vaccinum!=1 && vaccinum!=0){
            System.out.println("vaccinum error.");
            this.vaccinum=0;
        }
    }
    public void setPetType(String petType) {
        if (petType != null && !petType.trim().isEmpty()) {
            this.petType = petType;
        } else {
            System.out.println("宠物类型不能为空！");
            this.petType = "未知";
        }
    }
    public void setPetAge(double petAge) {
        if (petAge >= 0) {  
            this.petAge = petAge;
        } else{
            System.out.println("年龄错误.年龄过大,已设置为0。");
            this.petAge = 0;
        }
    }
    public void setVaccinum(byte vaccinum) {
        this.vaccinum = vaccinum;
        if(vaccinum!=1 && vaccinum!=0){
            System.out.println("error input.");
        }
    }
    public double getPetAge() {
        return petAge;
    }
    public String getPetType() {
        return petType;
    }
    public String getVaccinum() {
        if(vaccinum==1){
            return "是";
        }else if (vaccinum==0){
            return "否";
        }else{
            return "未知";
        }
    }
}
public class studyWorkPet {
    public static void main(String[] args){
        pet pet1=new pet("博美",(double)2,(byte)1);
        Scanner scanner=new Scanner(System.in);
        System.out.println("请输入宠物类型:");
        pet1.setPetType(scanner.nextLine());
        System.out.println("请输入宠物年龄:");
        pet1.setPetAge(scanner.nextDouble());
        System.out.println("请输入疫苗情况(1是0否):");
        pet1.setVaccinum(scanner.nextByte());
        System.out.println("宠物类型:"+pet1.getPetType());
        System.out.println("宠物年龄:"+pet1.getPetAge());
        System.out.println("是否接种疫苗:"+pet1.getVaccinum());
        scanner.close();
    }
}
