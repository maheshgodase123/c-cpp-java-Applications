// Problem On Pattern Printing.............

//INPUT  : 6
//OUTPUT : 1  * 3 * 5 *
// here logic is if no is even print *
//Complexity O(N)

#include<stdio.h>

void Display(int iNo)
{
	int iCnt = 0; 

	for(iCnt = 1; iCnt <= iNo; iCnt++)
	{
		if(iCnt % 2 == 0)
		{
			printf("*\t");
		}
		else
		{
			printf("%d\t", iCnt);
		}
		
	
	}

}

int main()
{

	int iValue = 0;

	printf("Please Enter The Value : \n");
	scanf("%d", &iValue);

	Display(iValue);

	return 0;
}