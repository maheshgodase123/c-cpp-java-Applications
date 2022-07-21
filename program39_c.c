// Array with loop 
// allocating dynamic memory to our array 

#include<stdio.h>
#include<stdlib.h>

void Display(int ptr[], int iLength)  
{
	int iCnt = 0;

	printf("Elements of array are :\n");

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		printf("%d\n", ptr[iCnt]); 			     
	}

}

int main()
{
	int *ptr = NULL;
	register int iCnt = 0, iSize = 0;
	
	printf("Enter The Size Of Array You Want : \n");
	scanf("%d", &iSize);

	ptr = (int *)malloc(iSize * sizeof(int)); // malloc - memory allocation
// we write (int *) bcoz our helper function returning (void *) value
// bt we want it into (int *) so we have typecast malloc in int using (int *)malloc()

	printf("Enter Elements : \n");

	for(iCnt = 0; iCnt < iSize; iCnt++)
	{
		scanf("%d", &ptr[iCnt]);
	}

	Display(ptr, iSize);
	free(ptr); // here we deallocate memory manually allocated by malloc
		     // no need to do manually bcoz garbage collector deallocates bt it is good sign of programmer to deallocate.
	return 0;
}