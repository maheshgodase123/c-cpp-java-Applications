#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE head)
{
	if(head == NULL)
	{
		printf("LINKED LIST IS EMPTY!!\n");
		return;  // you cannot return any value bcoz you are using void if value is given then it will give error
	}
	else
	{
		printf("Linked List Is : \n");
		while(head != NULL)
		{
			printf("|%d|->", head->data);	// bracket will treate *head as combination not like head and then its *
			head = head->next;
		}
	
		printf("\n");	// here i get to know that single inverted commas not works in printf
	}
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
	//create a new node that is going to insert
	// Allocate memory dynamically to the node
	// Initialize the node
	// check if linked list is empty
	// if empty assign the address of new node in first
	// if not then give the address of first pointer to next in new node and update address of first pointer

	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL;

	if(*head == NULL)	//ll is empty
	{
		*head = newn;
	}
	else
	{
		newn->next = *head;
		*head = newn;
	}

}

void InsertLast(PPNODE head, int no)
{
	// create new node
	// allocate memory to node
	// initialize this node
	// check ll is empty
	// if ll empty do same like insertfirst add address of newn to first
	// if not then traverse till last and and update null to new address

	PNODE newn = NULL;
	PNODE temp = NULL;

	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL;

	if(*head == NULL)
	{
		*head = newn;
	}
	else
	{
		temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
	
		temp->next = newn;		
	}
}

void DeleteFirst(PPNODE head)
{
	//  check ll is empty or not
	// if empty then return
	// if not then update address

	PNODE temp = NULL;

	if(*head == NULL)
	{
		printf("CANNOT PERFORM OPERATION LL IS EMPTY!!");
		return;
	}
	else
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void DeleteLast(PPNODE head)
{
	// check the ll empty or not
	// if empty then return
	// if not then traverse till second last node and then delete

	PNODE temp = NULL;

	if(*head == NULL)
	{
		printf("CANNOT PERFORM.LL IS EMPTY!!");
		return;
	}
	else
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
	int iCnt = 0;
	int iSize = 0;

	iSize = Count(*head);	//call by value

	PNODE newn = NULL;
	PNODE temp = NULL;

	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL;

	if(pos < 1 || pos > iSize+1)
	{
		return;
	}
	if(pos == 1)
	{
		InsertFirst(head, no);	//call by address
	}
	if(pos == iSize+1)
	{
		InsertLast(head, no);
	}
	else
	{
		temp = *head;

		for(iCnt = 1; iCnt < pos-1; iCnt++)
		{
			
			temp = temp->next;
		}	
	
		newn->next = temp->next;
		temp->next = newn;
	}
	
}

void DeleteAtPos(PPNODE head, int pos)
{
	int iCnt = 0;
	int iSize = 0;

	PNODE tempdelete = NULL;
	PNODE temp = NULL;

	iSize = Count(*head);	//call by value

	if(pos < 1 || pos > iSize)
	{
		return;
	}
	if(pos == 1)
	{
		DeleteFirst(head);	//call by address
	}
	if(pos == iSize)
	{
		DeleteLast(head);
	}
	else
	{
		temp = *head;

		for(iCnt = 1; iCnt < pos-1; iCnt++)
		{
			
			temp = temp->next;
		}	
	
		tempdelete = temp->next;
		temp->next = temp->next->next;
		free(tempdelete);
	}
	
}

int main()
{
	int iRet = 0;

	PNODE first = NULL;
	
	InsertFirst(&first, 101);	//call by address

	InsertLast(&first, 118);

	InsertLast(&first, 150);

	InsertFirst(&first, 21);

	InsertFirst(&first, 11);


	Display(first);	// call by value

	DeleteFirst(&first);

	Display(first);

	iRet = Count(first);
	printf("No Nodes Present In LL Are : %d\n", iRet);

	InsertLast(&first, 128);
	DeleteLast(&first);

	Display(first);

	InsertAtPos(&first, 51, 2);

	DeleteAtPos(&first, 6);

	Display(first);

	return 0;
}