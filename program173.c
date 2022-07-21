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

bool Search(PNODE head, int iNo)
{
	//bool flag = false;
	if(head == NULL)
	{
		printf("Tree Is Empty!!");
		return false;
	}

	while(head != NULL)
	{
		if(head->data == iNo)
		{
			//flag = true;
			break;
		}
		else if(iNo > head->data)
		{
			head = head->rchild;
		}
		else if(iNo < head->data)
		{	
			head = head->lchild;
		}
	}

	if(head == NULL)
	{
		return false;
	}	
	else
	{
		return true;
	}
	
}

int main()
{
	PNODE first = NULL;
	bool bret = false;

	Insert(&first,11);
	Insert(&first,21);
	Insert(&first,7);

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

	bret = Search(first,21);

	if(bret == true)
	{
		printf("Element Is Present!!\n");
	}
	else
	{
		printf("Element Is Not Present!!\n");
	}

	return 0;
}