// accept string and display maximum occur character

import java.util.*;
import java.lang.*;

class hashmapTraverse
{
	public static void main(String arg[])
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The String : ");

		String str = sobj.nextLine();

		char Arr[] = str.toCharArray();

		HashMap<Character, Integer> hobj = new HashMap<>();

		int Frequency = 0;

		for(char ch: Arr)
		{
			if(hobj.containsKey(ch))
			{
				Frequency = hobj.get(ch);
				hobj.put(ch, Frequency+1);
			}
			else
			{
				hobj.put(ch, 1);
			}
		}

		Set<Character> setobj = hobj.keySet();

		char max = '\0';
		int maxno = 0;
		int count = 0;

		for(char ch: setobj)
		{
			count = hobj.get(ch);
			if(maxno < count)
			{
				max = ch;
				maxno = count;
			}
		}

		System.out.printf("Maximum Occure Character Is %c : %d\n",max,maxno);
	}
}