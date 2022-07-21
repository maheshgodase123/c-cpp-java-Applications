// display perfect no

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE,**PPNODE;
 

void InsertFirst(PPNODE head, int iNo)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));

	newn->data = iNo;
	newn->next = NULL;

	if(*head != NULL)
	{
		newn->next = *head;
	}
	
	*head = newn;
}

void Display(PNODE head)
{
	printf("Elements of ll are : \n");

	while(head != NULL)
	{
		printf("|%d|->", head->data);
		head = head->next;
	}

	printf("\n");
}

void AddDigit(PNODE head)
{
	int iNo = 0, i = 0,iSum = 0, iDigit = 0;

	printf("Addition is : \n");
	while(head != NULL)
	{
		iNo = head->data;
		iSum = 0;

		while(iNo != 0)
		{
			iDigit = iNo % 10;

			iSum = iSum + iDigit;

			iNo = iNo/10;
		}

		printf("%d\t",iSum);
		head = head->next;
	}

}

int main()
{
	PNODE first = NULL;

	InsertFirst(&first, 6);
	InsertFirst(&first, 28);
	InsertFirst(&first, 30);
	InsertFirst(&first, 496);
	InsertFirst(&first, 128);

	Display(first);
	
	AddDigit(first);

	return 0;
}