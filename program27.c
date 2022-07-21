// Accept no and print its length

#include<stdio.h>

int CountDigits(int iNo)
{
	if(iNo < 0)
	{
		iNo = -iNo;
	}	

	int iCnt = 0;

	while(iNo != 0)
	{
		iCnt++;

		iNo = iNo / 10;
	}
	return iCnt;

}

int main()
{
	int iValue = 0;
	int iRet = 0;

	printf("Enter Number : ");
	scanf("%d", &iValue);

	iRet = CountDigits(iValue);
	printf("Length Of No Is : %d", iRet);

	return 0;
}