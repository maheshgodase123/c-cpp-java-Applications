// Accept no and print seperate no's 

#include<stdio.h>

int Reverse(int iNo)
{
	if(iNo < 0)
	{
		iNo = -iNo;
	}	

	int iDigit = 0;
	int iRev = 0;

	while(iNo != 0)
	{
		iDigit = iNo % 10;
		iRev = iRev*10 + iDigit;
		iNo = iNo / 10;
	}
	return iRev;
}

int main()
{
	int iValue = 0;
	int iRet = 0;

	printf("Enter Number : ");
	scanf("%d", &iValue);

	iRet = Reverse(iValue);
	printf("Reverse Order Is : %d", iRet);

	return 0;
}