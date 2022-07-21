// Accept string from user and count no of words in it

import java.io.*;
import java.util.*;

class program144
{

	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The String : ");

		String str = sobj.nextLine();

		String arr[] = str.split(" ");

		System.out.println("No Of Words In String Are : "+ arr.length);

		System.out.println(Arrays.toString(arr));		// jrr multipe whitspace dilya without any character tr kai hotay bghayla
	}
}
 