// Accept string from user and reverse each word and concatenate it.

import java.io.*;
import java.util.*;

class program148
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

		StringBuffer finalstr = new StringBuffer();	// navin string bnvli mutable

		for(int i = 0; i < arr.length; i++)
		{
			StringBuffer sb = new StringBuffer(arr[i]);
			finalstr.append((sb.reverse().append(" ")));
		//               3           1            2           (ha flow ahe adhi kuthla function run hoil)
		    // finalstr madhe append kara(reverse word ani tyala append space)
		}

		//System.out.println(finalstr);

		String finalstr2 = new String(finalstr);	// he karan aplya string la last la extra space append hoti
		// so we cannot use trim on string buffer so we will convert it into string and trim it
		System.out.println(finalstr2.trim());

	}
}
 