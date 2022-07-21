// Calculate Minimum no from array

#include<stdio.h>
#include<stdlib.h> // for malloc and free


int Minimum(int Arr[], int iLength)
{
	int iMin = Arr[0]; // works for negatice no's ass well  
	int iCnt = 0;

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(iMin > Arr[iCnt])
		{
			iMin = Arr[iCnt];
		}
	}

	return iMin;
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

	iRet = Minimum(ptr, iSize);
	printf("Min No Is : %d", iRet);

	free(ptr);
	return 0;

}

//TIME COMPLEXITY - N