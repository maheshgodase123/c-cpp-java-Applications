// Problem On Pattern Printing.............

//INPUT  : 5
//OUTPUT : * * * * *

#include<stdio.h>

void Display(int iNo)
{
	int iCnt = 0; 

	for(iCnt = 0; iCnt < iNo; iCnt++)
	{
		printf("*\t");
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