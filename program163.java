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
	
	PNODE temp = head;

	while(temp != NULL)
	{
		printf("|%d|->", temp->data);
		temp = temp->next
	}

	printf("\n")
}

int main()
{
	PNODE first = NULL;

	InsertFirst(&first, 50);
	InsertFirst(&first, 40);
	InsertFirst(&first, 30);
	InsertFirst(&first, 20);
	InsertFirst(&first, 10);

	Display(&first);

	return 0;
}