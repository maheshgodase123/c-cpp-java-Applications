// input 2d matrix and display it
// display the addition of each row matrix elements

import java.io.*;
import java.util.*;

class program154
{
	public static void main(String[] args)
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The Number Of Rows : ");
		int row = sobj.nextInt();

		System.out.println("Enter The Number Of Columns : ");
		int col = sobj.nextInt();

		int Arr[][] = new int[row][col];

		System.out.println("Enter the Elements : ");
		for(int i = 0; i < Arr.length; i++)		// by default arr.length mnje row chi ch length aste
		{
			for(int j = 0; j < Arr[i].length; j++)
			{
				Arr[i][j] = sobj.nextInt();
			}
		}
		
		System.out.println("Elments Are : ");
		for(int i = 0; i < Arr.length; i++)	
		{
			int sum = 0;
			for(int j = 0; j < Arr[i].length; j++)
			{
				sum = sum + Arr[i][j];
			}

			System.out.printf("Addition of %d row Is %d : \n",i+1, sum);
		}

	}
} 
