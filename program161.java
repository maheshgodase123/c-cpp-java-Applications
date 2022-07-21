import java.lang.*;
import java.util.*;
import java.io.*;

class Array
{
	public int Arr[];
	
	public Array(int iSize)
	{
		Arr = new int[iSize];
	}

	protected void finalize()
	{
		Arr = null;
	}

	public void Accept()
	{

		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter elements");

		for(int i=0; i<Arr.length; i++)
		{
			Arr[i] = sobj.nextInt();
		}
	}

	public void Display()
	{
		System.out.println("Elements From Array are : ");

		for(int i=0; i<Arr.length; i++)
		{
			System.out.println(Arr[i]); 
		}
	}
	
}

class program161
{
	public static void main(String[] arr)
	{
		Array aobj = new Array(5);
		aobj.Accept();
		aobj.Display();
	}
}