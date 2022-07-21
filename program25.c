// Accept no from user and check wheather no is prime or not

#include<stdio.h>
#include<stdbool.h>

int CountFactor(int iNo)
{
	int iCnt = 1;
	int iFactorCount = 0;

	if(iNo < 0)
	{
		iNo = -iNo;
	}

	for(iCnt = 2; iCnt <= iNo/2; iCnt++)
	{
		if(iNo % iCnt == 0)
		{
			iFactorCount++;
		}	
	}
	return iFactorCount;
}

bool ChkPrime(int iNo)
{
	bool bRet = false;

	int iRet = CountFactor(iNo)
	

	if(iRet == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	//for(iCnt = 2; iCnt <= iNo/2; iCnt++) logic without CountFactor
	//{
	//	if(iNo % iCnt == 0)
	//	{
	//		return false;
	//	}
	//}
	//return true;
}


int main()
{
	int iValue = 0;
	bool bRet = false;

	printf("Enter The Number : ");
	scanf("%d", &iValue);

      bRet = ChkPrime(iValue);

	if(bRet == true)
	{
		printf("%d IS A PRIME NUMBER!", iValue);
	}
	else
	{
		printf("%d IS NOT A PRIME NUMBER!", iValue);
	}
  

	return 0;
}