// accept string and display each occur word

import java.util.*;
import java.lang.*;

class hashmapTraverse2
{
	public static void main(String arg[])
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The String : ");

		String str = sobj.nextLine();
		
		str = str.trim();

		String Arr[] = str.split(" ");

		HashMap<String, Integer> hobj = new HashMap<>();

		int Frequency = 0;

		for(String ch: Arr)
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

		Set<String> setobj = hobj.keySet();

		String max = " ";
		int maxno = 0;
		int count = 0;

		for(String word: setobj)
		{
			System.out.println(word + " : " + hobj.get(word));
		}

		
	}
}