package work5.homework.object2.model;
public class Animal {
    private String animalName;
    private int animalAge;
    public Animal(){
        this.animalName="NULL";
        this.animalAge=0;
    }
    public Animal(String animalName,int animalAge){
        this.animalName=animalName;
        this.animalAge=animalAge;
    }
    public void setAnimalName(String animalName) {
        this.animalName = animalName;
    }
    public String getAnimalName() {
        return animalName;
    }
    public void setAnimalAge(int animalAge) {
        if(animalAge>=0){
            this.animalAge = animalAge;
        }else{
            System.out.println("Age error,set age be 0");
            this.animalAge=0;
        }
    }
    public int getAnimalAge() {
        return animalAge;
    }
    public void Shout(){
        System.out.println("发出了动物的叫声");
    }
    @Override
    public String toString() {
        return "一只"+getAnimalAge()+"岁的"+getAnimalName();
    }
}
