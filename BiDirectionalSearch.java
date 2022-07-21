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

class Searching extends Array
{
	public Searching(int iSize)
	{
		super(iSize);
	}
	public int BiDirectional(int iNo)
	{
		int start = 0;
		int end = Arr.length-1;

		while(start <= end)
		{
			if(Arr[start] == iNo)
			{
				return start;
			}
			else if(Arr[end] == iNo)
			{
				return end;
			}
			
			start++;
			end--;
		}
		
		return -1;
	}

}

class BiDirectionalSearch
{
	public static void main(String[] arr)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The Size Of Array : ");

		int size = sobj.nextInt();

		Searching aobj = new Searching(size);

		aobj.Accept();
		aobj.Display();

		System.out.println("Enter The Element To Search : ");

		int search_no = sobj.nextInt();

		int iRet = aobj.BiDirectional(search_no);

		if(iRet == -1)
		{	
			System.out.println("There is no such element!!");
		}
		else
		{
			System.out.printf("%d is present at position %d in Array ", aobj.Arr[iRet], iRet);
		}
	}
}