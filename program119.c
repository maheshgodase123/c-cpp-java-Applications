#include<stdio.h>

//output - *  *  *  *

void DisplayI()
{
	auto int iCnt = 0;	
	
	while(iCnt < 4)
	{
		printf("*\t");
		iCnt++;
	}
	printf("\n");
}

void DisplayR()
{
	//static int iCnt = 0;
	
	//if(iCnt < 4)
	//{
	//	printf("*\t");
	//}

	//DisplayR(iCnt++);		//recursive call

	// vrcha maza logic hota

	//int iCnt = 0;		// it does not preserve the value after function call bcoz it will again
					// again initialize with value 0 then again 1 then again 0 stuck in infinite loop
	
	static int iCnt = 0;

	if(iCnt < 4)
	{
		printf("*\t");
		iCnt++;
		DisplayR();
	}
}

int main()
{
	DisplayI();
	DisplayR();
	return 0;
}