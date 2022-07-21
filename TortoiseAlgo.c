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

// Also Known As Fast Forward Algorithm 
int Middle(PNODE head)
{
	PNODE Fast = head;
	PNODE Slow = head;

	while((Fast != NULL) && (Fast->next != NULL))
	{
		Fast = Fast->next->next;
		Slow = Slow->next;
	}

	return Slow->data;
}

int main()
{
	PNODE first = NULL;

	InsertFirst(&first, 6);
	InsertFirst(&first, 28);
	InsertFirst(&first, 30);
	InsertFirst(&first, 6);
	InsertFirst(&first, 128);

	Display(first);
	
	printf("%d", Middle(first));

	return 0;
}