//  anagram checki using sorting method

import java.io.*;
import java.util.*;

class anagram_b
{
    public static void main(String arg[])
    {  
            Scanner sobj = new Scanner(System.in);

            System.out.println("Enter first string : ");
            String str1 = sobj.nextLine();

            System.out.println("Enter second string : ");
            String str2 = sobj.nextLine();

		if(str1.length() != str2.length())
            {
                System.out.println("Strings are not anagram as lengths are different");
                return;
            }

		//str1 = str1.toLowerCase().toCharArray();
            //str2 = str2.toLowerCase()..toCharArray();

		char arr[] = str1.toLowerCase().toCharArray();
            char brr[] = str2.toLowerCase().toCharArray();

            Arrays.sort(arr);
		Arrays.sort(brr);

		if(Arrays.equals(arr,brr))	// return type true or false
		{
			System.out.println("Words Are Anagram");
		}
		else
		{
			System.out.println("Words Are Not Anagrams!!");	
		}
     }
}