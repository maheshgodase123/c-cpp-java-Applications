import java.lang.*;
import java.util.*;


//  0000	0000	0000	0000	0000	0000	0000	1000  if 4 bit is on
//   0  	  0	  0     0     0     0     0     8
class Bitwise
{
	public int OnBit(int no)
	{
		// below code will work for only 4th bit if bit is off make it on
		int iMask = 0X00000008; 
		int iResult = 0;

		iResult = no | iMask;

		return iResult;
	}
}

class program107
{
	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The No : ");

		int value = sobj.nextInt();

	
		Bitwise bobj = new Bitwise();

		int iRet = bobj.OnBit(value);

		System.out.println(iRet);
	}
}