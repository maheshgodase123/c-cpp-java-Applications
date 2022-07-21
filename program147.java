// Accept string from user and reverse each word.

import java.io.*;
import java.util.*;

class program147
{

	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The String : ");

		String str = sobj.nextLine();

		String newstr = str.replaceAll("\\s+"," "); 
	
		newstr = newstr.trim();

		String arr[] = newstr.split(" ");

		System.out.println(Arrays.toString(arr));

		for(int i = 0; i < arr.length; i++)
		{
			StringBuffer sb = new StringBuffer(arr[i]);	// string is immutbable in java so convert into stringbyffer
			
			// string buffer hi pn string ch ahe pn mutable

			System.out.println(sb.reverse());
		}

	}
}
 