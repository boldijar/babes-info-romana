public class TestClass
{
    public static void main(String[]args)
    {
        Complex a = new Complex(3, -6);
        Complex b = new Complex();
        b.Read();
        Complex c = a.add(b);
        System.out.println( a + " + " + b + " = " + c );
    }
}