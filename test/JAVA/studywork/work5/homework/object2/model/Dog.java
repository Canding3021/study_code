package work5.homework.object2.model;

public class Dog extends Animal{
    private String dogColor;
    public Dog(String animalName,int animalAge,String dogColor){
        super(animalName,animalAge);
        this.dogColor=dogColor;
    }
    public void setDogColor(String dogColor) {
        this.dogColor = dogColor;
    }
    public String getDogColor() {
        return dogColor;
    }
    @Override
    public String toString() {
        return super.toString()+"颜色是"+dogColor;
    }
    @Override
    public void Shout(){
        System.out.println("发出了汪汪汪的叫声");
    }
}
