// display summation of factors

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

void SumFactors(PNODE head)
{
	int iNo = 0, i = 0, iSum = 0;

	while(head != NULL)
	{

		for(i = 1,iSum = 0, iNo = head->data; i <= iNo/2; i++)
		{
			if(iNo % i == 0)
			{
				iSum = iSum + i;
			}
		}

		printf("%d : %d\n",head->data,iSum);
		head = head->next;
	}

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
	
	SumFactors(first);

	return 0;
}