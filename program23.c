// Aceept No From User print addition of factors

#include<stdio.h>
#include<stdbool.h>

/////////////////////////////////////////////////////////////////
//
// Function       : DisplayAddition
// Description    : Accepts no and display its factors
// Input          : Integer
// Output         : Integer
// Date           : 25/04/2022
// Author         : Mahesh Ankush Godase
//
/////////////////////////////////////////////////////////////////

bool ChkPerfectNo(int iNo)
{
	int iCnt = 0;
	int iSum = 0;	
	
	if(iNo < 0)
	{
		iNo = -iNo;
	}
	
	for(iCnt = 1; iCnt <= iNo/2; iCnt++)
	{
		if(iNo % iCnt == 0)
		{
			iSum = iSum + iCnt;
		}
	}

	if(iSum == iNo)
	{
		return true;
	}
}


int main()
{
	int iValue = 0;
	int iRet = 0;
      printf("Enter Number : ");
      scanf("%d", &iValue);

      iRet = ChkPerfectNo(iValue);
      if(iRet == true)
	{
		printf("%d No Is Perfect Number", iValue);
	}
	else
	{
		printf("%d No Is Not Perfect Number", iValue);
	}

      return 0;
}

/////////////////////////////////////////////////////////////////
//
// INPUT    : 20
// OUTPUT   : 22
//
// INPUT    : 15
// OUTPUT   : 9
//
// INPUT    : -20
// OUTPUT   : 22
//
/////////////////////////////////////////////////////////////////