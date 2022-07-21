// take string from user and count small letters from string

import java.io.*;
import java.util.*;

class program142
{

	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The String : ");

		String str = sobj.nextLine();

		//char arr[] = new char[str.length()] he apan manually kru sakto for loop laun string madhun ani array madhe elements takayche

		char arr[] = str.toCharArray();

		for(int i=0; i < arr.length; i++)
		{
			System.out.println(arr[i]);	
		}
	}
}
