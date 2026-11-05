using System.Security.Cryptography.X509Certificates;

public interface IArea
{
    double Area();
}
public class Rectangle : IArea
{
    public double X {get;set;}
    public double Y {get;set;}
    public Rectangle(double w,double h)
    {
        X = w;
        Y = h;
    }
    public double Area()
    {
        return X*Y;
    }
}
public class Circle : IArea
{
    public double X {get;set;}
    public Circle(double r)
    {
        X = r;
    }
    public double Area()
    {
        return Math.PI *X *X;
    }
}
public class Square : IArea
{
    public double X {get;set;}
    public Square(double I)
    {
        X = I;
    }
    public double Area()
    {
        return X*X;
    }
}
class Progream
{
    public static double FromArea(IArea re)
    {
        return re.Area();
    }
    static void Main()
    {
        double r = 3.0,h = 5.0;
        Rectangle rec = new Rectangle(r,h);
        Circle c = new Circle(r);
        Square s = new Square(r);
        Console.WriteLine("边长为{0}和{1}的矩形面积为{2}",rec.X,rec.Y,FromArea(rec));
        Console.WriteLine("半径为{0}的⚪面积为{1:0.00}",c.X,FromArea(c));
        Console.WriteLine("边长为{0}的正方面面积为:{1}",s.X,FromArea(s));
    }
}