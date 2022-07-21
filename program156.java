import java.lang.*;
import java.util.*;

/*
7 8 5 6 9
7 8 5 6 9
7 8 5 6 9
7 8 5 6 9
7 8 5 6 9
*/
class program156
{
	public static void main(String areg[])
	{	
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The No : ");
		int no = sobj.nextInt();

		String str = Integer.toString(no);

		char Arr[] = str.toCharArray();

		for(int i=0; i<Arr.length; i++)
		{
			for(int j=0; j < Arr.length; j++)
			{
				System.out.print(Arr[j] + " ");	
			}

			System.out.println();
		}
			
	}
}