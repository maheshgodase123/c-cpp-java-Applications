// Accept two strings from user and print no of occurence of characters.

// listen and silent are angram(no of characters and all characters are same)
// cat and act
// open and nope

import java.io.*;
import java.util.*;

class program150
{

	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The Word : ");

		String str = sobj.nextLine();
		
		str = str.toLowerCase();	// fakt lower case char allow krtoy 

		char arr[] = str.toCharArray();
		
		System.out.println(Arrays.toString(arr));

		int Frequency[] = new int[26];	// char 26 astat a-z count increase karaycha 1-26
		for(int i = 0; i < arr.length; i++)
		{
			Frequency[arr[i] - 97]++;	 //ascci value(ex if Frequency[a(97) - 97]++) mnje brobr 1st position la Frequency array madhe +1 hoil same for all 
			//Frequency[arr[i] - 'a']++;	// asa pn taku shakto
		}

		for(int i=0; i < Frequency.length; i++)
		{
			if(Frequency[i] > 0)
			{
				System.out.println((char)(i+97)+" : "+ Frequency[i]);
			}
		}

		int iMax = Frequency[0];
		int iPos = 0;

		for(int i = 0; i < Frequency.length; i++)
		{
			if(Frequency[i] > iMax)
			{
				iMax = Frequency[i];
				iPos = i;
			}
		}

		System.out.println((char)(iPos+'a') + " Occurs " + iMax + " number of times In String");
	}
}
 