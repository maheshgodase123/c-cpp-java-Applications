// accept one no from user and check it is armstrong no or not

#include<stdio.h>
#include<stdbool.h>

// checks armstrong no

bool ChkArmStrong(int iNo)
{
	if(iNo < 0)
	{
		iNo = -iNo;
	}

	int iSum = 0, iNo_len = 0, iCopy = iNo, iDigit = 0, iCnt = 0;
	
// calculation of digits

	while(iNo != 0)
	{
		iNo_len++;
		iNo = iNo / 10;
	}

// so iNo becomes zero recopying iCopy into again in iNo
	iNo = iCopy;

// calculation addition

	while(iNo != 0)
	{
		long int lMult = 1;
		iDigit = iNo % 10;
		for(iCnt = 1; iCnt <= iNo_len; iCnt++)
		{
			lMult = lMult * iDigit;
		}
		iSum = iSum + lMult;
		iNo = iNo / 10;
	}

	if(iSum == iCopy)
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

	printf("Enter The No : ");
	scanf("%d", &iValue);

	bRet = ChkArmStrong(iValue);
	if(bRet == true)
	{
		printf("%d is a Armstrong No!",iValue);
	}
	else
	{			
		printf("%d is Not a Armstrong No!",iValue);

	}

	return 0;
}