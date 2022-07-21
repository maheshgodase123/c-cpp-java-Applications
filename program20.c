// accept no from user and print its factors

#include<stdio.h>

/////////////////////////////////////////////////////////////////
//
// Function       : DisplayFactors
// Description    : Accepts no and display its factors
// Input          : Integer
// Output         : Integer
// Date           : 25/04/2022
// Author         : Mahesh Ankush Godase
//
/////////////////////////////////////////////////////////////////


void DisplayFactors(int iNo)
{
	if(iNo < 0)
	{
		iNo = -iNo;
	}

	int iCnt = 0;
	printf("Factors Are : ");
	for(iCnt = 1; iCnt <= iNo/2; iCnt++)  // iNo/2 we use becoz we have to reduce time complexity
//and our loop is running unnecceserilly after half part of no bcoz ex 10 is no after 5 10
// cannot have its factor(i.e 1 2 5) so if we use iNo only complexity will be "N" and after 
// using n/2 complexity is "N/2"  
	{
		if(iNo % iCnt == 0)
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

     DisplayFactors(iValue);

     return 0;

}

/////////////////////////////////////////////////////////////////
//
// INPUT    : 20
// OUTPUT   : 1 2 4 5 10
//
// INPUT    : 15
// OUTPUT   : 1 3 5
//
// INPUT    : -20
// OUTPUT   : 1 2 4 5 10
//
/////////////////////////////////////////////////////////////////
