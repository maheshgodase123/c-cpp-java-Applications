import java.io.*;
import java.util.*;

class program319
{
    public static void main(String arg[])
    {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Enter first string : ");
            String str1 = sobj.nextLine();

            str1 = str1.toLowerCase();

            char arr[] = str1.toCharArray();
            int Frequency[] = new int[26];

            System.out.println("Enter second string : ");
            String str2 = sobj.nextLine();

            str2 = str2.toLowerCase();

            char brr[] = str2.toCharArray();

            if(str1.length() != str2.length())
            {
                System.out.println("Strings are not anagram as lengths are different");
                return;
            }

            int i = 0;

		// optimise kela mnje don array ghenya aivaji akch ghetla str1 madhe sapdla char trr +1 ani str2 madhe sapdla tr -1 end la sagle 0 astil count tr anagram ahe
            for(i = 0; i < arr.length; i++)
            {
                Frequency[arr[i] - 'a']++;
                Frequency[brr[i] - 'a']--;
            }

            for(i = 0; i < Frequency.length; i++)
            {
                if(Frequency[i] != 0)
                {
                    break;
                }
            }

            if(i == 26)
            {
                System.out.println("Strings are anagram");
            }
            else
            {
                System.out.println("Strings are not anagram");
            }
     }
}