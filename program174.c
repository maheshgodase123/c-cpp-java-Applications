// Display count of Leaf Nodes Of the tree

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE head, int iNo)
{

	PNODE temp = *head;
	PNODE newn = (PNODE)malloc(sizeof(NODE));

	newn->data = iNo;
	newn->lchild = NULL;
	newn->rchild = NULL;

	if(*head == NULL)
	{
		*head = newn;
	}
	else
	{
		while(1)
		{
			if(iNo > temp->data)			// right side
			{
				if(temp->rchild == NULL)
				{
					temp->rchild = newn;
					break;
				}
				temp = temp->rchild;
			}
			else if(iNo < temp->data)		// left side
			{		
				if(temp->lchild == NULL)
				{
					temp->lchild = newn;
					break;
				}
				temp = temp->rchild;
			}
			else if(iNo == temp->data)		// duplicate side
			{
				free(newn);
				printf("Data is already there in BST");
				break;
			}
		}
	}

}

void Inorder(PNODE head)
{

	if(head != NULL)
	{
		Inorder(head->lchild);
		printf("%d ",head->data);
		Inorder(head->rchild);
	}
}

void Preorder(PNODE head)
{
	if(head != NULL)
	{
		printf("%d ",head->data);
		Preorder(head->lchild);
		Preorder(head->rchild);
	}
}

void Postorder(PNODE head)
{
	if(head != NULL)
	{
		Postorder(head->lchild);
		Postorder(head->rchild);
		printf("%d ",head->data);
	}
}

// leaf node count karaycha asel tr purn tree traverse karavi lagel
// ani ti fakt atta apan recurssion nech kru shakto
// ani paratyek stackframe madhe count reset hou naye mhanun apan static count ghenar

int CountLeafNodes(PNODE head)
{
	static int count = 0; 

	if(head != NULL)
	{
		if((head->lchild == NULL) && (head->rchild == NULL))
		{	
			count++;
		}

		CountLeafNodes(head->lchild);		// left subtree  sathi
		CountLeafNodes(head->rchild);		// right subtree sathi
	}

	return count;
	
}

int main()
{
	PNODE first = NULL;
	int iret = 0;

	Insert(&first,11);
	Insert(&first,21);
	Insert(&first,9);
	Insert(&first,27);
	Insert(&first,18);

	// 7 11 21  left root right    -- Inorder(root madhe mhanun in)
	// 11 7 21  root left right	 -- Preorder(root adhi mhanun pre)
	// 7 21 11  left right data	 -- Postorder(root nantar mhanun post)

	printf("Inorder data : \n");
	Inorder(first);

	printf("\nPreorder data : \n");
	Preorder(first);

	printf("\nPostorder data : \n");
	Postorder(first);

	printf("\n");

	iret = CountLeafNodes(first);
	
	printf("No Of LeafNodes Are : %d ", iret);

	return 0;
}