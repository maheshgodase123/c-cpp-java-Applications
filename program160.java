  // toggle 4rt bit

import java.lang.*;
import java.util.*;

class program160
{
	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The First No : ");

		int value1 = sobj.nextInt();
		

		System.out.println("Enter The Second No : ");

		int value2 = sobj.nextInt();

		int value = value1 & value2;	//(common bits miltil on aslyala)
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