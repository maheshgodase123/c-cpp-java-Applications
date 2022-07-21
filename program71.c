// DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;	//*(ha siranni sangitlela symbol jrr kahi navin asel dusya code pekshya trr asa * comment karaycha)

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE head)
{
	printf("Data From Linked List Is : \n");
	while(head != NULL)
	{
		printf("| %d |<=>",head->data);
		head = head->next;
	}
	printf(" NULL\n");
}

int Count(PNODE head)
{
	int iCnt = 0;

	while(head != NULL)
	{
		iCnt++;
		head = head->next;
	}

	return iCnt;
}

void InsertFirst(PPNODE head, int no)
{
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));

	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;	//*


	//if( *head == NULL) we can write *head = newn; outside if not null
	//{
	//	*head = newn;
	//}
	if(*head != NULL)
	{
		newn->next = *head;
		(*head)->prev = newn; // or we can write(newn -> next -> prev = newn;)	//*	
	}

	*head = newn;  //*

	// in above, code will not enter in if it is not empty and statement will work
	// and if will work also that statement will work
}

void InsertLast(PPNODE head, int no)
{
	PNODE newn = NULL;
	PNODE temp = NULL;

	newn = (PNODE)malloc(sizeof(NODE));

	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;	//*


	if( *head == NULL)
	{
		*head == newn;
	}
	else
	{
		temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
		newn->prev = temp;	//*  temp->next->prev = temp;
	}
}

void DeleteFirst(PPNODE head)
{
	if(*head == NULL)
	{
		return;	
	}

	if((*head)->next == NULL) //single node //Jithe pn *head ani pudhe next lihaycha asel tr bracket taka *head la
	{
		free(*head);
		*head = NULL;
	}
	else  // More than one node
	{
		*head = (*head)->next;	//*
		free((*head)->prev);	//*
		(*head)->prev = NULL;	//*
		
	}
}

void DeleteLast(PPNODE head)
{
	PNODE temp = NULL;

	if(*head == NULL)
	{
		return;	
	}

	if((*head)->next == NULL) //single node //Jithe pn *head ani pudhe next lihaycha asel tr bracket taka *head la
	{
		free(*head);
		*head = NULL;
	}
	else  // More than one node
	{
		temp = *head;

		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		free(temp->next);
		temp->next = NULL;
		
	}
}

void InsertAtPos(PPNODE head, int no, int pos)
{
	int size = 0;
	int iCnt = 0;
	PNODE temp = NULL;
	PNODE newn = NULL;
	size = Count(*head);

	if((pos < 1) || (pos > size+1))
	{
		printf("Invalid Position!!\n");
		return;
	}
	
	if(pos == 1)
	{
		InsertFirst(head, no);
	}	
	else if(pos == size+1)
	{
		InsertLast(head, no);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));

		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;	//*

		temp = *head;

		for(iCnt = 1; iCnt < (pos-1); iCnt++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next->prev = newn;	//*
		temp->next = newn;
		newn->prev = temp;	//*
	}
}

void DeleteAtPos(PPNODE head, int pos)
{
	int size = 0;
	int iCnt = 0;
	PNODE temp = NULL;
	int tempDel = 0;

	size = Count(*head);

	if((pos < 1) || (pos > size))
	{
		printf("Invalid Position!!\n");
		return;
	}
	
	if(pos == 1)
	{
		DeleteFirst(head);
	}	
	else if(pos == size)
	{
		DeleteLast(head);
	}
	else
	{

		temp = *head;

		for(iCnt = 1; iCnt < (pos-1); iCnt++)
		{
			temp = temp->next;
		}

		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
		
		
	}
}

int main()
{

	PNODE first = NULL;
	int iret = 0;

	InsertFirst(&first, 21);
	InsertFirst(&first, 11);

	InsertLast(&first, 51);
	InsertLast(&first, 101);

	Display(first);
	iret = Count(first);

	printf("Number Of Nodes Are : %d \n", iret);
	
	InsertAtPos(&first,75,3);
	Display(first);

	DeleteAtPos(&first,3);
	Display(first);

	DeleteFirst(&first);
	DeleteLast(&first);

	Display(first);
	iret = Count(first);

	printf("Number Of Nodes Are : %d \n", iret);

	InsertAtPos(&first, 102, 3);

	Display(first);
	iret = Count(first);

	printf("Number Of Nodes Are : %d \n", iret);



	return 0;
} 