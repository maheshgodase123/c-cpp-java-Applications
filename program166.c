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

void DisplayPerfect(PNODE head)
{
	int iNo = 0, i = 0, iSum = 0;

	printf("Perfect Nos Are : \n");
	while(head != NULL)
	{

		for(i = 1,iSum = 0, iNo = head->data; i <= iNo/2; i++)
		{
			if(iNo % i == 0)
			{
				iSum = iSum + i;
			}
		}

		if(iSum == iNo)
		{
			printf(" %d ",iNo);
		}
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
	
	DisplayPerfect(first);

	return 0;
}