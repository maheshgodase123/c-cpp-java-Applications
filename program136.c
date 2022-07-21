// Accept Array From User And return Addition Of Elements

#include<stdio.h>

int SumI(int Arr[], int iSize)
{
	int i = 0;
	int iSum = 0;

	while(i < iSize)
	{
		iSum = iSum + Arr[i];
		i++;
	}
	return iSum;
}

int SumR(int Arr[], int iSize)
{
	static int iSum = 0;
	// without i variable bcoz ak static variable wadhto
	if(iSize > 0)
	{
		iSum = iSum + Arr[iSize-1];
		iSize--;
		SumR(Arr, iSize);
	}
	return iSum;
}

int main()
{
	int Brr[] = {10,20,30,40};
	int iRet = 0;

	int size = sizeof(Brr)/sizeof(Brr[0]);	// mi he vrchya function madhe lihila hota mnje 
								// Arr use krun pn Arr ha apla pointer ahe tyamadhe
								// apla 1st element cha adress ahe tyamule khali
								// size kadhlelich better

 	iRet = SumR(Brr,size);

	printf("Summation Is : %d\n",iRet);

	return 0;
} 