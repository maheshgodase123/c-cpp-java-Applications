// Calculate Frequency of that no in array

#include<stdio.h>
#include<stdlib.h> // for malloc and free


int ChkOccurence(int Arr[], int iLength, int iNo)
{
	int iMin = Arr[0]; // works for negatice no's ass well  
	int iCnt = 0;
	int iFrequency = 0;

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(Arr[iCnt] == iNo)
		{
			iFrequency++;
		}
	}

	return iFrequency;
}
int main()
{
	int iSize = 0, iCnt = 0, iRet = 0, iValue = 0;
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

	iRet = ChkOccurence(ptr, iSize, iValue);
	printf("Frequency of that no Is : %d", iRet);

	free(ptr);
	return 0;

}

//TIME COMPLEXITY - N