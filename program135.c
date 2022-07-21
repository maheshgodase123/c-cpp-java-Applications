#include<stdio.h>


int FactorialI(int iNo)
{
	int iFact = 1;

 	while(iNo > 0)
	{
		iFact = iFact * iNo;
		iNo--;
	}

	return iFact;
}

int FactorialR(int iNo)
{
	static int iFact = 1;		// static mnje pratyekveles function call hoil tyaweles
						// value 1 ni nahi initialize honar magchi value tyamadhe 
						// store rahil adhichi value mhanun static use hota

	if(iNo > 0)
	{
		iFact = iFact * iNo;
		iNo--;
		FactorialR(iNo);
	}
	
	return iFact;

}

int main()
{
	int iValue = 0;
	int iRet = 0;

	printf("Enter The Number\n");
	scanf("%d",&iValue);

	iRet = FactorialR(iValue);

	printf("Factorial Is : %d\n",iRet);
	return 0;
}