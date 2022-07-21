import java.lang.*;
import java.util.*;

class Bitwise
{
	public boolean CheckBit(int no)
	{
		// below code will work for only 21th bit
		int iMask = 0X00100000;       //1048576 we can write value like this bt write like this
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