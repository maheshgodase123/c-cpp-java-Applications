// find no in the array and print its first occurence index

#include<stdio.h>
#include<stdlib.h> // for malloc and free


int SearchFirstOccurence(int Arr[], int iLength, int iNo)
{  
	int iCnt = 0;

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(Arr[iCnt] == iNo) 
		{
			break;
		}
	}

	if(iCnt == iLength)
	{
		return -1;
	}
	else
	{
		return iCnt;
	}

}

int main()
{
	int iSize = 0, iCnt = 0, iValue = 0, iRet = 0;
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

	printf("Enter Number To Check Frequency : \n");
	scanf("%d", &iValue);

	iRet = SearchFirstOccurence(ptr, iSize, iValue);

	if(iRet == -1)
	{
		printf("The No Is Not Present!!");
	}
	else
	{
		printf("The First Occurence Of No Is At Index : %d", iRet);
	}

	free(ptr);
	return 0;

}

//TIME COMPLEXITY - N