// search the no and return frequency

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

int Frequency(PNODE head, int no)
{
	int cnt = 0;

	while(head != NULL)
	{
		if((head->data) == no)
		{
			cnt++;
		}
	
		head = head->next;
	}

	return cnt;
}

int main()
{
	PNODE first = NULL;

	InsertFirst(&first, 50);
	InsertFirst(&first, 20);
	InsertFirst(&first, 30);
	InsertFirst(&first, 20);
	InsertFirst(&first, 10);

	Display(first);
	
	printf("Enter the no to search frequency : \n");
	int value = 0;

	scanf("%d", &value);
	printf("Frequency Of No : %d\n", Frequency(first, value));

	return 0;
}