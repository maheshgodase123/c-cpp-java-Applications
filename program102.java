// this is just the template to use further

import java.lang.*;
import java.util.*;

class Bitwise
{
	public void DisplayBinary(int no)
	{
		int iDigit = 0;
		
		while(no > 0)
		{
			iDigit = no % 2;
			System.out.print(iDigit);

			no /= 2; 
		}

		System.out.println();
	}
}

class program102
{
	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The No : ");

		int value = sobj.nextInt();

	
		Bitwise bobj = new Bitwise();

		bobj.DisplayBinary(value);
	}
}