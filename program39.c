// Array with loop 

#include<stdio.h>

void Display(int iNo, int *ptr)  // here we take value in pointer so it will point to data of 
				         // address(100)

// Array is treated as internally in c/c++ and pointer can be use as array.
// so from above statement we can write like this ptr[] on befalf of *ptr.
// internally it passes adress int bracket ex- ptr[100] and ptr++.

{
	int iCnt = 0;

	printf("Elements of array are :\n");

	for(iCnt = 0; iCnt < iNo; iCnt++)
	{
		printf("%d\n", *ptr);
		ptr++;  // it is arithmatic pointer means it goes to the next adress

// ++ means increase pointer by 1(i.e go to next node)
			     
	}

}

int main()
{
	register int iCnt = 0;
	int iValue = 0;
	
	printf("Enter The Size Of Array You Want : \n");
	scanf("%d", &iValue);

	auto int Arr[iValue];

	printf("Enter Elements : \n");

	for(iCnt = 0; iCnt < iValue; iCnt++)
	{
		scanf("%d", &Arr[iCnt]);
	}

	Display(iValue, Arr); // this is call by address means here it passes adress(ex-100) of
			  // first element in array it does not pass whole array.

	return 0;
}