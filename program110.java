// toggle 4rt bit

import java.lang.*;
import java.util.*;


//  0000	0000	0000	0000	0000	0000	0100	1000
//   0  	  0	  0     0     0     0     4     8


// toggle 4th and 7th bit
// 0000 1001 - given no
// 0100 1000 - mask
// (given no ^ mask)after toggle below ans
// 0100 0001  - final ans
class Bitwise
{
	public int OnBit(int no)
	{
		// below code will work for only 27th bit if bit is off make it on
		int iMask = 0X00000048; 
		int iResult = 0;

		iResult = no ^ iMask;

		return iResult;
	}
}

class program110
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