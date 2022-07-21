// Accept no and print summation of even no's 

#include<stdio.h>

int DisplayDigits(int iNo)
{
	if(iNo < 0)
	{
		iNo = -iNo;
	}	

	int iDigit = 0;
	int iSum = 0;

	while(iNo != 0)
	{
		iDigit = iNo % 10;
            if(iDigit % 2 == 0)
		{
			iSum = iSum + iDigit;
		}

		iNo = iNo / 10;
	}
	return iSum;
}

int main()
{
	int iValue = 0;
	int iRet = 0;

	printf("Enter Number : ");
	scanf("%d", &iValue);

	iRet = DisplayDigits(iValue);
	printf("Summation is : %d", iRet);

	return 0;
}