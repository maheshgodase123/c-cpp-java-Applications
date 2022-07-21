import java.lang.*;
import java.util.*;

// check wheather 15 bit is on
// 0000 0000 0000 0000 0100 0000 0000 0000
//  0     0    0    0    4   0     0    0

class BitWise
{
	public boolean ChkBit(int no)
	{
		int iMask = 0X00004000;
		int result = 0;

		result = no & iMask;

		if(result == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

class program1
{
	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The No :");
		int value = sobj.nextInt();

		BitWise obj = new BitWise();

		boolean bret = obj.ChkBit(value);

		if(bret == true)
		{
			System.out.println("Bit Is On");	
		}
		else
		{
			System.out.println("Bit Is Off");
		}
	}
}