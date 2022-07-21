// search last occurence no

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

int LastOccurence(PNODE head, int iNo)
{
	int iCnt = 0, ipos = 0;
	while(head != NULL)
	{
		if(iNo == head->data)
		{
			ipos = iCnt; 
		}
		
		iCnt++;
		
		head = head->next;
	}

	return ipos;

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
	
	printf("%d", LastOccurence(first, 6));

	return 0;
}