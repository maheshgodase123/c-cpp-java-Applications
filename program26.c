// Accept no and print seperate no's 

#include<stdio.h>

void DisplayDigits(int iNo)
{
	if(iNo < 0)
	{
		iNo = -iNo;
	}	

	int iDigit = 0;
	while(iNo != 0)
	{
		iDigit = iNo % 10;
		printf("%d\t", iDigit);

		iNo = iNo / 10;
	}

}

int main()
{
	int iValue = 0;

	printf("Enter Number : ");
	scanf("%d", &iValue);

	DisplayDigits(iValue);

	return 0;
}