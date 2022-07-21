// accept no from user and return sum of digits

#include<stdio.h>

int SumI(int iNo)
{
	int digit = 0;
	int sum = 0;

	while(iNo != 0)
	{
		digit = iNo % 10;
		sum = sum + digit;
		iNo = iNo/10;
	}

	return sum;
}

int SumR(int iNo)
{
	static int sum = 0;
	int digit = 0;

	if(iNo != 0)
	{
		digit = iNo % 10;
		sum = sum + digit;
		iNo = iNo/10;
		
		SumR(iNo);
	}

	return sum;
}

int main()
{
	int iValue = 0;
	int iRet = 0;

	printf("Enter The No :\n");
	scanf("%d",&iValue);

	iRet = SumR(iValue);

	printf("Addition Is : %d\n",iRet);

	return 0;
}