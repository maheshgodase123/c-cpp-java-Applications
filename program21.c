// accept no from user and print its Nonfactors

#include<stdio.h>

/////////////////////////////////////////////////////////////////
//
// Function       : DisplayNonFactors
// Description    : Accepts no and display its Nonfactors
// Input          : Integer
// Output         : Integer
// Date           : 25/04/2022
// Author         : Mahesh Ankush Godase
//
/////////////////////////////////////////////////////////////////


void DisplayNonFactors(int iNo)
{
	if(iNo < 0)
	{
		iNo = -iNo;
	}

	int iCnt = 0;
	printf("Factors Are : ");
	for(iCnt = 1; iCnt <= iNo; iCnt++)  
	{
		if(iNo % iCnt != 0)
		{
			printf("%d ", iCnt);
		}
	}

}

int main()
{
     int iValue = 0;

     printf("Enter Number : ");
     scanf("%d", &iValue);

     DisplayNonFactors(iValue);

     return 0;

}

/////////////////////////////////////////////////////////////////
//
// INPUT    : 20
// OUTPUT   : 3 6 7 8 9 11 12 13 14 15 16 17 18 19
//
// INPUT    : 8
// OUTPUT   : 3 5 6 7
//
// INPUT    : -20
// OUTPUT   : 3 6 7 8 9 11 12 13 14 15 16 17 18 19
//
/////////////////////////////////////////////////////////////////
