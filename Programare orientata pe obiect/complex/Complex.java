import java.util.Scanner;
public class Complex
{
    private double re,im;
    public Complex(double re, double im)
    {
        this.re = re;
        this.im = im;
    }
    public Complex()
    {
        //
        //this(0,0);
        //re = 0, im=0;
        
    }
    public void Read()
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Re=");
        re = s.nextDouble();
        System.out.println("Im = " );
        im = s.nextDouble();
        
    }
    public Complex add(Complex c )
    {
        return new Complex(re+c.re, im + c.im);
    }
    public String toString()
    {
        String r = "";
        if ( re != 0 )
        r += re;
        if ( im > 0 )
        {
            if (re!= 0 ) r+="+";
            r += im + "i";
        }
        else 
        if ( im < 0 )
        r += im + "i";
        else 
        if ( re==0 ) r = "0";
        return r;
    }
}