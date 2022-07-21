// return middle element

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

int Middle(PNODE head)
{
	int iSize = 0, ipos = 0;
	PNODE temp = head;
	while(head != NULL)
	{	
		iSize++;
		
		head = head->next;
	}

	for(int i = 0; i < iSize/2; i++)
	{
		temp = temp->next;
	}

	return temp->data;
}

int main()
{
	PNODE first = NULL;

	InsertFirst(&first, 6);
	InsertFirst(&first, 28);
	InsertFirst(&first, 30);
	InsertFirst(&first, 6);
	//InsertFirst(&first, 128);

	Display(first);
	
	printf("%d", Middle(first));

	return 0;
}