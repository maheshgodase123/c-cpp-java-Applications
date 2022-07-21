// checking  no in array bidirectionally and without using bflag

#include<stdio.h>
#include<stdlib.h> // for malloc and free
#include<stdbool.h>


bool Search(int Arr[], int iLength, int iNo)
{
	int iMin = Arr[0]; // works for negatice no's ass well  
	int iCnt = 0;
	int iFrequency = 0;
	bool bFlag = false;

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(Arr[iCnt] == iNo || Arr[iLength - iCnt] == iNo)  // checking bidirectionally
		{
			break;
		}
	}

	if(iCnt == iLength)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	int iSize = 0, iCnt = 0, iValue = 0;
	int *ptr = NULL;
	bool bRet = 0;


	printf("Enter Number Of Elements : \n");
	scanf("%d", &iSize);

	if(iSize < 0)
	{
		iSize = -iSize;
	}

	ptr = (int *)malloc(iSize * sizeof(int));

	printf("Enter Values of Array : \n");

	for(iCnt = 0; iCnt < iSize; iCnt++)
	{
		scanf("%d", &ptr[iCnt]);
	}

	printf("Enter Number To Check Frequency : \n");
	scanf("%d", &iValue);

	bRet = Search(ptr, iSize, iValue);

	if(bRet == true)
	{
		printf("The No Is Present!!");
	}
	else
	{
		printf("Not Present!!");
	}

	free(ptr);
	return 0;

}

//TIME COMPLEXITY - N/2 directly becomes half becouse biderectionally checking