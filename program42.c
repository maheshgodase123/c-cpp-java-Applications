// Calculate largest no from array

#include<stdio.h>
#include<stdlib.h> // for malloc and free


int Maximum(int *Arr, int iLength)
{
	int iMax = 0;  // works only for positive values or mixed values not for nrgative values
                     // bcoz negative is less than 0. not enters in if statement.
	int iCnt = 0;

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(iMax < Arr[iCnt])
		{
			iMax = Arr[iCnt];
		}
	}

	return iMax;
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
	
	iRet = Maximum(ptr, iSize);
	printf("Max No Is : %d", iRet);

	free(ptr);
	return 0;

}