#include<stdio.h>
#include<stdlib.h>

struct node // delaration of structure i.e use to create node
{
	int data;	        // 4 byte
	struct node*next;   // 8 byte
};

typedef struct node NODE; //for our ease
typedef struct node * PNODE; //for our more ease
typedef struct node ** PPNODE;



int main()
{
	// Static memory allocation
	//struct node obj;
	// NODE obj;     After using typedef

	// Dynamic memory allocation
	//struct node *ptr = (struct node *)malloc(sizeof(struct node));
	//NODE *ptr = (NODE *)malloc(sizeof(NODE));
	PNODE ptr = (PNODE)malloc(sizeof(NODE));



	//obj.data = 11;    // Direct accessing operator
	//obj.next = Null;  // use when we allocate static memory

	ptr -> data = 11;  // Indirect accessing operator
	ptr -> next = NULL;

	return 0;
}