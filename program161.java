// accept 2 string from user and check if 1st string is rotation of 2nd(approch concat comparison algo)

//str1  hello
//str2 lohel

// str3 = hellohello  (concatenating same string i.e given)
// and search the given string in concatinating string(in our case lohel is present hence its rotation string)

import java.util.*;
import java.lang.*;

class program161
{
	public static void main(String args[])
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("enter the first string : ");
		
		String str1 = sobj.nextLine();

		System.out.println("enter the second string : ");

		String str2 = sobj.nextLine();

		if(str1.length() != str2.length())
		{
			System.out.println("String are not in rotation");
			return;
		}

		String str3 = str1 + str2;

		if(str3.contains(str2))
		{
			System.out.println("String Are In Rotation");
		}
		else
		{
			System.out.println("String Are Not In Rotation");
		}
	}
}

