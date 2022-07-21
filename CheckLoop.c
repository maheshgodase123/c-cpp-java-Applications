// Detect if loop is present in ll
// means consider 100->200->300->400->500->300(expected null)
// so it will create loop which will never stop

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool CheckLoop(PNODE head)
{
	bool Flag = false;

	PNODE Fast = head;
	PNODE Slow = head;

	while((Fast != NULL)&&(Fast->next != NULL))
	{
		Slow = Slow->next;
		Fast = Fast->next->next;

		if(Fast == Slow)
		{
			Flag = true;
			break;
		}
	}

	return Flag;
}

int main()
{
	PNODE first = NULL;
	bool bRet = false;

	PNODE Third = NULL;	// he pointer kashyasathi ghetlet karan
	PNODE Last = NULL;	// jrr loop detect karaycha tr tyala loop code madhe generate karava lagel mhanun
	// he pointers ghetlet

	InsertFirst(&first, 50);
	InsertFirst(&first, 40);
	InsertFirst(&first, 30);
	InsertFirst(&first, 20);
	InsertFirst(&first, 10);

	Third = first;
	Last = first;

	Third = Third->next->next;	// 300
	Last = Last->next->next->next->next; // 500

	Last->next = Third; // 500->300

	bRet = CheckLoop(first);

	if(bRet == true)
	{
		printf("There Is Loop In LL\n");
	}
	else
	{
		printf("There Is No Loop in LL\n");
	}

	return 0;
}