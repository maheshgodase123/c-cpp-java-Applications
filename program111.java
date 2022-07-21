// accept no from user and pos of bit and toggle bit ata that pos

import java.lang.*;
import java.util.*;


//  0000	0000	0000	0000	0000	0000	0000	0000	// this is 32bit(4byte) representation of no
//   0  	  0	  0     0     0     0     0     0


class Bitwise
{
	public int OnBit(int no, int pos)
	{
		if(pos <= 0 || pos > 32)
		{
			System.out.println("Invalid Position");
			return 0;
		}
		// below code will work for only 27th bit if bit is off make it on
		int iMask = 0X00000001;
		int iResult = 0;

		iMask = iMask << (pos-1); // making mask dynamicalli by user given pos(it will left shift 1 to till pos)
		iResult = no ^ iMask;

		return iResult;
	}
}

class program111
{
	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The No : ");

		int value = sobj.nextInt();

		System.out.println("Enter The Pos Of Bit : ");
		
		int value2 = sobj.nextInt(); 
	
		Bitwise bobj = new Bitwise();

		int iRet = bobj.OnBit(value, value2);

		System.out.println("No After Toggle : "+iRet);
	}
}