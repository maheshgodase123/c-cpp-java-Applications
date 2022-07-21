// Accept two strings from user and check if they are anagram.

// listen and silent are angram(no of characters and all characters are same)
// cat and act
// open and nope

import java.io.*;
import java.util.*;

class anagram
{

	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The First String : ");

		String str1 = sobj.nextLine();
		
		char arr[] = str1.toCharArray();
		int Frequency1[] = new int[26];		// char count maintain thevnya sathi reffer program150

		System.out.println("Enter The Second String : ");

		String str2 = sobj.nextLine();

		char brr[] = str1.toCharArray();
		int Frequency2[] = new int[26];	// if jrr don letter same astil str1 madhe tr r str2 madhe akch letter asel tr te tyachyasobtch compare hoil(ex hello - helo)
		// asa output yeil pn te wrong ahe mhanun char count maintain kara


		for(int i = 0; i < arr.length; i++)
		{
			Frequency1[arr[i] - 'a']++;
		}

		for(int i = 0; i < brr.length; i++)
		{
			Frequency2[brr[i] - 'a']++;
		}

		boolean flag = true;

		for(int i = 0; i < Frequency1.length; i++)
		{
			if(Frequency1[i] != Frequency2[i])
			{
				flag = false;
				break;
			}	
		}

		if(flag)
		{
			System.out.println("Words Are Anagrams");
		}
		else
		{
			System.out.println("Words Are Not Anagrams");
		}
	}
}
 