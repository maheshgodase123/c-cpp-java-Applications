// singly linear linked list


/*  REQUIRE FUNCTIONS

	InsertFirst
	InsertLast
	InsertAtPosition

	DeleteFirst
	DeleteLast
	DeleteAtPosition

	Display
	Count

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;

	//InsertFirst(&First, 11)

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE; //** means pointer to pointer

// struct node              NODE
// struct node *            PNODE
// struct node **           PPNODE

/*
    1 : Allocate memory for node
    2 : Initialise the node
    3 : Check whether LL is empty or not
    4 : If LL is empty the new node is the first node
    5 : If LL contains atleast one node in it then store the address of previous first node in the next pointer of new node

*/

void InsertFirst(PPNODE Head, int iNo)
{
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = iNo;
	newn->next = NULL;

	if(*Head == NULL)  // if ll is empty
	{
		*Head = newn;
	}
	else
	{
		newn -> next = *Head;
		*Head = newn;
	}
	
}

void Display(PNODE Head)
{

	printf("\n");
	while(Head != NULL)
	{
		printf("%d\t", Head -> data);
		Head = Head -> next;
	}
	printf("\n");
}

int main()
{

	PNODE First = NULL;  //struct node *First
	// hence we have created Pointer Named First (8 byte memory allocated)
	// having adress of struct node (we can say engine of train) VIP

	//PNODE = (PNODE *)malloc(PNODE*sizeof(NODE));

	InsertFirst(&First, 90);
	InsertFirst(&First, 110);
	InsertFirst(&First, 2000);
	InsertFirst(&First, 10000);

	Display(First);

	return 0;
}

/*
RULES
	1. Use only dynamic memory allocation
	2. Dont't write any technical syntax in main
	3. Don't use any global variables
	4. Be careful while manipulating the First pointer 
	5. Pass the Fisrt pointer directly if the function is not going to modify the LL(Display, Count)
	6. Pass the adress of First pointer if the function is going to modify the LL(All reamining neglecting Display and count)


*/