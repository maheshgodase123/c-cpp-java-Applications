// Accept string from user and handle multiple whitespace issue

import java.io.*;
import java.util.*;

class program145
{

	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The String : ");

		String str = sobj.nextLine();

		String newstr = str.replaceAll("\\s+"," ");  // '\\s+' he regx expression ahe yacha meaning more than one whitespaces replace with one whitespace
		
		// pn last ani front spaces problems detat mg both ends chya spaces weglya handle  karavya lagtil (trim use) 
	
		newstr = newstr.trim();

		String arr[] = newstr.split(" ");

		System.out.println("No Of Words In String Are : "+ arr.length);

		System.out.println(Arrays.toString(arr));		// jrr multipe whitspace dilya without any character tr kai hotay bghayla
	}
}
 