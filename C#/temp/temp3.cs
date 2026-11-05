public class Dimensions
{
    public const double PI = Math.PI;
    public double x, y;

    public Dimensions(double x, double y)
    {
        this.x = x;
        this.y = y;
    }


    public virtual double Area()
    {
        return 0;
    }
}

public class Rectangle : Dimensions
{

    public Rectangle(double l, double w) : base(l, w) { }

    public override double Area()
    {
        return x * y;
    }
}

public class Circle : Dimensions
{
    public Circle(double r) : base(r, 0) { }

    public override double Area()
    {
        return PI * x * x;
    }
}

public class Square : Dimensions
{
    public Square(double l) : base(l, 0) { }

    public override double Area()
    {
        return x * x;
    }
}

class Program
{
    public static double FromArea(Dimensions re)
    {
        return re.Area();
    }
    static void Main()
    {
        double r = 3.0, h = 5.0;
        Rectangle rec = new Rectangle(r, h);
        Circle c = new Circle(r);
        Square s = new Square(r);
        Console.WriteLine("边长为 {0} 和 {1} 的矩形面积为: {2}", rec.x, rec.y, FromArea(rec));
        Console.WriteLine("半径为 {0} 的圆形面积为: {1:0.00}", c.x, FromArea(c));
        Console.WriteLine("边长为 {0} 的正方形面积为: {1}", s.x, FromArea(s));
    }
}