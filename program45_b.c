// find no in the array and print its last occurence index

#include<stdio.h>
#include<stdlib.h> // for malloc and free


int SearchLastOccurence(int Arr[], int iLength, int iNo)
{  
	int iCnt = 0;

	for(iCnt = iLength-1; iCnt >= 0; iCnt--)
	{
		if(Arr[iCnt] == iNo) 
		{
			break;
		}
	}

	return iCnt; // if no not present then it automatically become -1
			 // bcoz if no will not present iCnt become 0 and iCnt-- gives 0-1 = -1 

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

	iRet = SearchLastOccurence(ptr, iSize, iValue);

	if(iRet == -1)
	{
		printf("Element Is Not Present!!");
	}
      else
	{
		printf("The Last Occurence Is At Index : %d", iRet);
	}

	free(ptr);
	return 0;

}

//TIME COMPLEXITY - N