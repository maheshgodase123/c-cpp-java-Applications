// Count even no of array

#include<stdio.h>
#include<stdlib.h> // for malloc and free


int CountEven(int Arr[], int iLength)
{
	int iCnt = 0, iCntEven = 0;

	printf("Even No From Array Are : \n");
	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(Arr[iCnt] % 2 == 0)
		{
			iCntEven++;
		}

	}

	return iCntEven;

}
int main()
{
	int iSize = 0, iCnt = 0, iRet = 0;
	int *ptr = NULL;


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

	iRet = CountEven(ptr, iSize);
	printf("Count Is : %d", iRet);

	free(ptr);
	return 0;

}