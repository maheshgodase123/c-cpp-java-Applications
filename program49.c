// Problem On Pattern Printing.............

//INPUT  : 5
//OUTPUT : 5 * 4 * 3 * 2 * 1 *
// Complexity O(N)

#include<stdio.h>

void Display(int iNo)
{
	int iCnt = 0; 

	for(iCnt = iNo; iCnt > 0; iCnt--)
	{
		printf("%d\t*\t",iCnt);
	
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