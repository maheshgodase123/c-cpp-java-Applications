import java.lang.*;
import java.util.*;
import MarvellousMatrix.Matrix;

class MyMatrix extends Matrix
{
    public MyMatrix(int a, int b)
    {
        super(a,b);
    }

    public int Maximum()
    {

        return 0;
    }

}

class program332
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number of rows");
        int X = sobj.nextInt();
c
        System.out.println("Enter number of columns");
        int Y = sobj.nextInt();

        Matrix mobj = new Matrix(X,Y);
        mobj.Accept();
        mobj.Display();
    }
}