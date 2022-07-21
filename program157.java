import java.lang.*;
import java.util.*;

class program157
{
	public static void main(String areg[])
	{	
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter The No : ");
		int no = sobj.nextInt();
		
		int sum = 0;

		while(true)
		{
			while(no != 0)
			{
				int digit = no % 10;
				sum = sum + digit;
				no = no/10;
			}
			System.out.println(sum);
			no = sum;
			sum = 0;

			if(no < 10)
			{
				break;
			}
		}
	
		
			
	}
}