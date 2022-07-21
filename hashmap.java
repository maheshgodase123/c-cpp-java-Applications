// use hash map to calculate frequency of letters

import java.util.*;
import java.lang.*;

class hashmap
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

		System.out.println(hobj);
	}
}