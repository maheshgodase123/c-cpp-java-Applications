import java.lang.*;
import java.util.*; 	// for input

class Pattern
{
	private int iRow, iCol;	

	public Pattern(int a, int b)	// Constructor
	{
		iRow = a;
		iCol = b;
	}
	
	public void Display()
	{
		int i = 0, j = 0;

		for(i = 1; i <= iRow; i++)
		{
			for(j = 1; j <= iCol; j++)
			{
				System.out.println("*\t");
			}
			System.out.println();
		}
	}


	
}

class program76
{
	public static void main(String args[])
	{
		Pattern nobj = new Pattern(4,4);  //obj is created

		nobj.Display();
	}
}