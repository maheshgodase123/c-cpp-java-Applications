// Display even no of array

#include<stdio.h>
#include<stdlib.h> // for malloc and free


void DisplayEven(int Arr[], int iLength)
{
	int iCnt = 0;
	
	if(iLength < 0)
	{
		iLength = -iLength;
	}

	printf("Even No From Array Are : \n");
	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(Arr[iCnt] % 2 == 0)
		{
			printf("%d\n", Arr[iCnt]);
		}

	}

}
int main()
{
	int iSize = 0, iCnt = 0;
	int *ptr = NULL;


	printf("Enter Number Of Elements : \n");
	scanf("%d", &iSize);
	ptr = (int *)malloc(iSize * sizeof(int));

	printf("Enter Values of Array : \n");
	for(iCnt = 0; iCnt < iSize; iCnt++)
	{
		scanf("%d", &ptr[iCnt]);
	}

	DisplayEven(ptr, iSize);
	free(ptr);
	return 0;

}