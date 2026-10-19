using System.Globalization;

class Car
{
    public string type;
    public float weight;
    public string color;
    
    public Car(string type,float weight,string color)
    {
        this.type = type;
        this.color = color;
        this.weight = weight;
    }
    public void showInfo()
    {
        Console.WriteLine("我是{0},重量为{1}吨,颜色是{2}",type,weight,color);
    }
    public void weight_2()
    {
        Console.Write(weight*2);
    }
}
class Program
{
    static void Main(String[] args)
    {
        string t;
        float w;
        string c;
        Car c1 = new Car("大众 Golf",1.295f,"白");
        Console.Write("请输入汽车型号");
        t = Console.ReadLine();
        Console.Write("请输入汽车重量:");
        w = float.Parse(Console.ReadLine());
        Console.Write("请输入汽车颜色:");
        c = Console.ReadLine();
        Car c2 = new Car(t,w,c);
        c1.showInfo();
        c2.showInfo();
    }
}