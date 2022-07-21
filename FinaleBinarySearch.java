import java.lang.*;
import java.util.*;
import java.io.*;

// Final Binary Search Program = BinarySearch + OrderAgnosticBinarySearch
// Order Agnostic mnje jrr array descending order madhe asel trr

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
	public int Binary(int iNo)
	{
		int start = 0;
		int end = Arr.length-1;

		if(Arr[start] < Arr[end])		// checking if arr is ascending or descending 
		{
			if(iNo < Arr[start] || iNo > Arr[end])
			{
				System.out.println("Filters Is Executed!!");
				return -1;
			}

			while(start <= end)
			{
				int mid = start + ((end - start)/2);

				if(iNo > Arr[mid])
				{
					start = mid+1;
				}
				else if(iNo < Arr[mid])
				{
					end = mid-1;
				}
				else
				{
					return mid;
				}
			}
		}
		else
		{
			if(iNo > Arr[start] || iNo < Arr[end])
			{
				System.out.println("Filters Is Executed!!");
				return -1;
			}
			while(start <= end)
			{
				int mid = start + ((end - start)/2);

				if(iNo > Arr[mid])
				{
					end = mid-1;
				}
				else if(iNo < Arr[mid])
				{
					start = mid+1;
				}
				else
				{
					return mid;
				}
			}
			
		}
	
		return -1;
	}
		

}

class FinaleBinarySearch
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

		int iRet = aobj.Binary(search_no);

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