// Accept no and print seperate no's 

#include<stdio.h>
#include<stdbool.h>

bool Reverse(int iNo)
{
	if(iNo < 0)
	{
		iNo = -iNo;
	}	

	int iDigit = 0;
	int iCopy = iNo;
	int iRev = 0;

	while(iNo != 0)
	{
		iDigit = iNo % 10;
		iRev = iRev*10 + iDigit;
		iNo = iNo / 10;
	}

	if(iCopy == iRev)
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

	iRet = Reverse(iValue);
	if(iRet == true)
	{
		printf("%d Is Palindrome!", iValue);
	}
	else
	{
		printf("%d Is Not a Palindrome!", iValue);
	}

	return 0;
}