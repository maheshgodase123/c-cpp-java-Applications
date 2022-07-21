#include<stdio.h>
#include<stdlib.h>

struct node // declaring structure
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head, int no) //kdhipn pointer pass karaycha asel tr to **
{
	// Allocate memory for node (Dynamically)
	// Initialise that node

	// Check wheather LL is empty or not
	// If LL is empty the new node is the first node so update its address in first pointer through head

	// If LL is not empty then 
	// travel till last node of ll
	// store address of new node in the next pointer of last node

	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL; 

	if(*head == NULL) //LL is empty
	{	
		*head = newn;
	}
	else  // LL contains atleast one node
	{
		newn->next = *head;
		*head = newn;
	
	}

}


void InsertLast(PPNODE head, int no) //kdhipn pointer pass karaycha asel tr to **
{
	//Allocate memory for node (Dynamically)
	//Initialise that node

	//Check wheather LL is empty or not
	//If LL is empty the new node is the first node so update its address in first pointer through head

	//If LL is not empty then store the address of first node in the next pointer of our new node
	// update the first pointer through head

	PNODE newn = NULL;
	PNODE temp = *head;


	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL; 

	if(*head == NULL) //LL is empty
	{	
		*head = newn;
	}
	else  // LL contains atleast one node
	{

		// travel till last node
		// store address of new node  in the next pointer of last node


		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
	
	}

}

void Display(PNODE head)
{
	printf("Elements from linked list are : \n");
	
	while(head != NULL)
	{
		printf("| %d |->", head->data);
		head = head -> next;
	}
	printf("NULL\n");
}

int Count(PNODE head)
{
	int iCnt = 0;
	
	while(head != NULL)
	{
		iCnt++;
		head = head -> next;
	}
	
	return iCnt;
}

void DeleteFirst(PPNODE head)
{
	// If LL is empty then return
	// Ift LL contains atleast one node then
	// store the address of second node in the first pointer through head
	// And delete the first node

	PNODE temp = NULL;

	if(*head == NULL)
	{
		return;
	}
	else
	{
		temp = *head;
		*head = temp->next;
		free(temp);

	}

}
void DeleteLast(PPNODE head)
{
	// If LL is empty then return
	// If LL contains one node then delete that node and return
	// If LL contains more than one node then travel till second last node and delete last node

	PNODE temp = NULL;

	if(*head == NULL)  // LL is empty
	{
		return;
	}
	else if((*head)->next == NULL)  //LL contains one node
	{
		free(*head);
		*head == NULL;  // It is most important so teacher(first) will understand there is no one in ll 
	}
	else  // ll cointains more than one node
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
	// If pos is invalid then return directly
	// if pos is 1 then call insertfirst
	// is pos is n+1 then call insertlast
	
	int size = 0;
	int iCnt = 0;
	PNODE newn = NULL;
	PNODE temp = NULL;
	size = Count(*head); // call by value dukanat call kelyamule *head nahitr first

	if((pos < 1) || (pos > (size+1)))
	{
		printf("Position is invalid\n");
		return;
	}

	if(pos == 1)  // At 1st Pos
	{
		InsertFirst(head, no);
	}
	else if(pos == (size+1))  // At Last Pos
	{
		InsertLast(head, no);
	}
	else  // Logic
	{

		newn = (PNODE)malloc(sizeof(NODE));

		newn->data = no;
		newn->next = NULL;

		temp = *head; 

		for(iCnt = 1; iCnt < pos-1; iCnt++)
		{
			temp = temp -> next;
		}

		newn->next = temp->next;
		temp->next = newn;
		
	}


}

void DeleteAtPos(PPNODE head, int pos)
{

	/*

      if position is invalid then return directly
      if position is 1 then call deletefirst
      if position is N then call deletelast




       */

 	int size = 0 , iCnt = 0;
 	size = Count(*head);
 	PNODE temp= NULL;
	PNODE tempdelete = NULL;  // just to delete the node

 	if ((pos <1)||(pos >size))
 	{
   		printf("position is invalid \n");
    
   		return ;
 	}

 	if (pos == 1)
 	{
  		DeleteFirst(head);
 
 	}
	else if (pos == size)
 	{
  		DeleteLast(head);
 	}
	else    //logic 
	{
  
     		temp = *head;
  
   		for (iCnt = 1;iCnt < pos-1; iCnt++)
   		{

   			temp = temp -> next ;

   		}

		tempdelete = temp->next;
   		temp ->next = temp->next->next;
		free(tempdelete);		

	}


}


int main()
{
	PNODE first = NULL;
	int iRet = 0;
	int iValue = 0;

	InsertFirst(&first, 101);
	InsertFirst(&first, 51);
	InsertFirst(&first, 21);
	InsertFirst(&first, 11);  // call by address

	InsertAtPos(&first, 75, 3);
	InsertLast(&first, 110);  // call by address

	Display(first);

	DeleteAtPos(&first,3);

	Display(first);  //call by value

	iRet = Count(first);
	printf("Nodes Present In The List Are : %d \n", iRet);

	InsertFirst(&first, 1);
	
	Display(first);

      iRet = Count(first);
	printf("Nodes Present In The List Are : %d \n", iRet);


	DeleteFirst(&first);
	DeleteLast(&first);


      Display(first);  //call by value

	iRet = Count(first);
	printf("Nodes Present In The List Are : %d \n", iRet);


	return 0;
}