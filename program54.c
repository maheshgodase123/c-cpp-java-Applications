// Problem On Pattern Printing.............

//INPUT  : 4  4
//OUTPUT : 1 2 3 4
//	       1 2 3 4	
//         1 2 3 4
//         1 2 3 4
// here logic is if no is even print *
// Complexity O(2N)

#include<stdio.h>

void Display(int iRow, int iColumn)
{
	int iCntRow = 0, iCntColmn = 0;

	for(iCntRow = 1; iCntRow <= iRow; iCntRow++)
	{
		for(iCntColmn = 1; iCntColmn <= iColumn; iCntColmn++)
		{
			printf("%d\t", iCntColmn);
		}	

		printf("\n");
	}


}

int main()
{

	int iValue1 = 0;
	int iValue2 = 0;

	printf("Please Enter The Value of Rows: \n");
	scanf("%d", &iValue1);

	printf("Please Enter The Value of Columns: \n");
	scanf("%d", &iValue2);

	Display(iValue1, iValue2);

	return 0;
}