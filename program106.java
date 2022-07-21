import java.lang.*;
import java.util.*;


//  0000	0000	0000	0000	0010	0000	0000	0000  if 14 bit is on
//   0  	  0	  0     0     2     0     0     0
class Bitwise
{
	public boolean CheckBit(int no)
	{
		// below code will work for only 14th bit
		int iMask = 0X00002000;       //8192
		int iResult = 0;

		iResult = no & iMask;	// using '&' bitwise operator

		if(iResult == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

class program105
{
	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The No : ");

		int value = sobj.nextInt();

	
		Bitwise bobj = new Bitwise();

		boolean bret = bobj.CheckBit(value);

		if(bret == true)
		{
			System.out.println("Bit is On");
		}
		else
		{
			System.out.println("Bit is Off");
		}
	}
}