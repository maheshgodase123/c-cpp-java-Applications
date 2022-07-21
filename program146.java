// Accept string from user and print largest word in the string

import java.io.*;
import java.util.*;

class program146
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

		int iMax = arr[0].length(), Maxindex = 0;

		for(int i = 0; i < arr.length; i++)
		{
			if(arr[i].length() > iMax)
			{
				iMax = arr[i].length();
				Maxindex = i;
			}
		}

		System.out.println("Largest Word : "+ arr[Maxindex]);
	}
}
 