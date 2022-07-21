// Accept no from user and check wheather no is prime or not

#include<stdio.h>
#include<stdbool.h>


bool ChkPrime(int iNo)
{
	int iCnt = 0;

	if(iNo < 0)
	{
		iNo = -iNo;
	}

	for(iCnt = 2; iCnt <= iNo/2; iCnt++) 
	{
		if(iNo % iCnt == 0)
		{
			break;  //don't write return statements in any loops
		}
	}
	if(iCnt == (iNo/2)+1)
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