// accept string and find given word and replace each of that word

import java.util.*;
import java.lang.*;

class hashmapTraverseReplace
{
	public static void main(String arg[])
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The String : ");

		String str = sobj.nextLine();

		System.out.println("Enter The Word To Search");

		String word = sobj.nextLine();

		System.out.println("Enter The Word To Replace");

		String word2 = sobj.nextLine();
		
		str = str.trim();

		String Arr[] = str.split(" ");

		String newstr = " ";

		for(String value: Arr)
		{
			if(value.equals(word))
			{
				newstr = newstr + " " + word2;
			}	
			else
			{
				newstr = newstr + " " + value;
			}
		}

		System.out.println("New String is : "+ newstr);
	}
}