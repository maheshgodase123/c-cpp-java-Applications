// take no from user and print its factorial

#include<stdio.h>

int Factorial(int no)
{
	int iFact = 1;
	int iCnt = 0;

	for(iCnt=1; iCnt<= no; iCnt++)
	{
		iFact = iFact*iCnt;
	}

	return iFact;
}
int main()
{
	int iValue = 0;
	int iRet = 0;

	printf("Enter The Number : \n");
	scanf("%d", &iValue);

	iRet = Factorial(iValue);

	printf("Factorial Is : %d\n", iRet);
	return 0;
}