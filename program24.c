// Aceept No From User print the no is perfect or not.

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

int DisplayAddition(int iNo)
{
	int iCnt = 0;
	int iSum = 0;	
	
	if(iNo < 0)
	{
		iNo = -iNo;
	}
	
	for(iCnt = 1; ((iCnt <= iNo/2) && (iSum <= iNo)); iCnt++)
	{
		if(iNo % iCnt == 0)
		{
			iSum = iSum + iCnt;
		}
            //if(iSum > iNo)  // this is basic like if addition is greater that iNo
                            // i.e(given no) so there is no possibility that no is perfect so stop there so
                            // time complexity will reduce. and for short code i directly put
                            // condition in for loop (iSum <= iNo) 
		//{
		//	break;
		//}
	}

      return iSum;
}

/////////////////////////////////////////////////////////////////
//
// Function       : ChkPerfect
// Description    : Accepts no and check no is perfect or not
// Input          : Integer
// Output         : Bool
// Date           : 25/04/2022
// Author         : Mahesh Ankush Godase
//
/////////////////////////////////////////////////////////////////

bool ChkPerfect(int iNo)
{
	int iAns = 0;
      iAns = DisplayAddition(iNo);
      if(iAns == iNo)
	{
		return true;
	}
      else
	{
		return false;
	}
}

int main()
{
	int iValue = 0;
	int iRet = 0;
      printf("Enter Number : ");
      scanf("%d", &iValue);

      iRet = ChkPerfect(iValue);
      if(iRet == true)
	{
		printf("%d Is Perfect Number", iValue);
	}
	else
	{
		printf("%d Is Not Perfect Number", iValue);
	}

      return 0;
}

/////////////////////////////////////////////////////////////////
//
// INPUT    : 6 i.e (1+2+3 = 6) perfect no is sum of factor == that no
// OUTPUT   : 6 Is Perfect Number
//
// INPUT    : 28 i.e (1+2+4+7+14 = 28)
// OUTPUT   : 28 Is Perfect Number
//
// INPUT    : 4 i.e (1+2 = 3)
// OUTPUT   : 4 Is Not Perfect Number
//
/////////////////////////////////////////////////////////////////