import java.lang.*;
import java.util.*;

/*
h e l l o
h e l l
h e l
h e
h
*/
class program154
{
	public static void main(String areg[])
	{	
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The String : ");
		String str = sobj.nextLine();

		char Arr[] = str.toCharArray();

		for(int i=Arr.length-1; i >= 0; i--)
		{
			for(int j=0; j <= i; j++)
			{
				System.out.print(Arr[j] + " ");
			}

			System.out.println();
		}		
	}
}