  // toggle 4rt bit

import java.lang.*;
import java.util.*;

class program159
{
	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The No : ");

		int value = sobj.nextInt();
		
		int iMask = 0x00000001;	// decimal - 1
		int iResult = 0;
		
		System.out.println("On Bits Are : ");
		for(int i=1; i<= 32; i++)
		{
			iResult = value & iMask;
		
			if(iResult == iMask)
			{
				System.out.println(i);
			}
		
			iMask = iMask <<1;	// pryatyek weles on krun(1) 1 ne bit shift karel right la
		}
	}
}