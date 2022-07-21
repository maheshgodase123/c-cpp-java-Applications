import java.lang.*;
import java.util.*;

interface MarvellousSort
{
    public void Accept();
    public void Display();
    public void BubbleSort();
    public void InsertionSort();
    public void SelectionSort();
}

class Array implements MarvellousSort
{
    public int Arr[];

    public Array(int iSize)
    {
        Arr = new int[iSize];
    }

    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter elements");
        for(int i= 0;i <Arr.length; i++)
        {
            Arr[i] = sobj.nextInt();
        }
    }

    public void Display()
    {
        System.out.println("Elements of the array are");
        for(int i= 0;i <Arr.length; i++)
        {
           System.out.print(Arr[i]+ " ");
        }
	  System.out.println();
    }

    public void BubbleSort()
    {
        int i = 0,j = 0, temp = 0;

	  boolean Swap = false;

        for(i = 0; i < Arr.length; i++)
	  {
		Swap = false;
		// for every pass(every loop of j) one elements gets settled(means max elements sets ata rightmost position)
		for(j = 0; j < Arr.length-i-1; j++)
		{

			if(Arr[j] > Arr[j+1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = temp;
				Swap = true;
			}
			System.out.println("Pass : "+ (i+1));
			Display();	// just for checking impementation how passes are going
			
		}
		
		if(Swap == false)		// it increase efficiency of code means 
		// if whole j loop executed and not a single swapping is done means already the array is sorted
		{
			break;
		}
	  }
    }

    public void InsertionSort()
    {
	    int i = 0,j = 0,selected = 0;

	    for(i = 1; i < Arr.length; i++)
	    {
		    for(j = i-1, selected = Arr[i]; (j >=0) && (Arr[j] > selected); j--)
		    {
		         Arr[j+1] = Arr[j];
		    }

		    Arr[j+1] = selected;
	    }
    }

    public void SelectionSort()
    {
	    // Selection Sort is just searches the smallest no and replace with leftmost index
	    // means 1st smallest with 0th index, second smallest with 1st index and so on
	    int index_of_min = 0;

	    for(int i = 0; i < Arr.length-1; i++)
	    {
		    index_of_min = i;
		    
 		    for(int j = i+1; j < Arr.length; j++)
		    {
			     if(Arr[index_of_min] > Arr[j])		// decresing sathi sighn change kra
			     {
					index_of_min = j;
			     }
		    }

		    if(i != index_of_min)		// ugach kashala swap karaychay
		    {
		        int temp = Arr[i];
		        Arr[i] = Arr[index_of_min];
		        Arr[index_of_min] = temp;
		    }
	    }
    }
}

class Sorting
{
    public static void main(String arr[])
    {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Enter the size of array : ");
            int size = sobj.nextInt();

            Array aobj = new Array(size);
            aobj.Accept();
            aobj.Display();

		//aobj.BubbleSort();
		//System.out.println("Data after sorting");
		//aobj.Display();

		//aobj.SelectionSort();
		//System.out.println("Data after sorting");
		//aobj.Display();

		aobj.InsertionSort();
		System.out.println("Data after sorting");
		aobj.Display();
    }
}