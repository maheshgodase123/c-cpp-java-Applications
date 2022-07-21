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

// Cyclic Development Algorithm
void Reverse(PPNODE head)		// pass by reference bcoz inplace swapping
{
	PNODE Prev = NULL;
	PNODE Curr = *head;
	PNODE Nxt = NULL;

	while(Curr != NULL)
	{
		Nxt = Curr->next;
		Curr->next = Prev;
		Prev = Curr;
		Curr = Nxt;
	}

	*head= Prev;
}

int main()
{
	PNODE first = NULL;

	InsertFirst(&first, 50);
	InsertFirst(&first, 40);
	InsertFirst(&first, 30);
	InsertFirst(&first, 20);
	InsertFirst(&first, 10);

	printf("Before Reverese\n");
	Display(first);
	
	Reverse(&first);
	printf("After Reverse\n");
	Display(first);

	return 0;
}