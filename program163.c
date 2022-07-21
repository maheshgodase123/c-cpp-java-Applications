// search the largest no from ll

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

int Maximum(PNODE head)
{
	int iMax = -1;

	if(head != NULL)
	{
		iMax = head->data;
	}

	while(head != NULL)
	{
		if((head->data) > iMax)
		{
			iMax = head->data;
		}
	
		head = head->next;
	}

	return iMax;
}

int main()
{
	PNODE first = NULL;

	InsertFirst(&first, 50);
	InsertFirst(&first, 40);
	InsertFirst(&first, 30);
	InsertFirst(&first, 20);
	InsertFirst(&first, 10);

	Display(first);

	printf("Maximum No : %d\n", Maximum(first));

	return 0;
}