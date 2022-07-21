#include<iostream>

using namespace std;

struct node
{
	int data;
	int iCnt;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCircular_LL
{

	private:
		PNODE head;
		PNODE tail;
		int iCnt;

	public:

		DoublyCircular_LL();
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAtPos(int, int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		inline int Count();
		inline void Display();
		void Head_Tail();
};

DoublyCircular_LL:: DoublyCircular_LL()
{
	head = NULL;
	tail = NULL;
	iCnt = 0;
}

void DoublyCircular_LL:: InsertFirst(int no)
{
	PNODE newn = NULL;

	newn = new NODE;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((head == NULL) && (tail == NULL))
	{
		head = newn;
		tail = newn;
	}
	else
	{
		newn->next = head;	
		head->prev = newn;
		head = newn;
	}

	tail->next = head;
	head->prev = tail;

	iCnt++;
}

void DoublyCircular_LL:: InsertLast(int no)
{
	PNODE newn = NULL;

	newn = new NODE;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((head == NULL) && (tail == NULL))
	{
		head = newn;
		tail = newn;
	}
	else
	{
		tail->next = newn;
		newn->prev = tail;
		tail = newn; 	
	}
	tail->next = head;
	head->prev = tail;

	iCnt++;
}

void DoublyCircular_LL::InsertAtPos(int no, int pos)
{
	int size = Count();

	if((pos < 0) || (pos > size+1))
	{
		cout<<"Invalid Position!!"<<endl;
		return;
	}
	
	if(pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		PNODE newn = NULL;
		PNODE temp = NULL;
	
		newn = new NODE;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		temp = head;
		for(int iCnt = 1; iCnt < pos-1; iCnt++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next->prev = newn;
		newn->prev = temp;
		temp->next = newn;

		iCnt++;

	}
}

void DoublyCircular_LL::DeleteFirst()
{
	if(head == NULL && tail == NULL)
	{
		cout<<"Cannot Perform Delete Operation LL Empty!!"<<endl;
		return;
	}
	PNODE temp = head;
	
	head = head->next;
	head->prev = tail;
	tail->next = head;
	delete temp;
	iCnt--;
}

void DoublyCircular_LL::DeleteLast()
{
	if(head == NULL && tail == NULL)
	{
		cout<<"Cannot Perform Delete Operation LL Empty!!"<<endl;
		return;
	}
	
	PNODE temp = tail;	
	tail = tail->prev;
	tail->next = head;
	head->prev = tail;

	delete temp;

	iCnt--;
}

void DoublyCircular_LL::DeleteAtPos(int pos)
{

	int size = Count();

	if(head == NULL && tail == NULL)
	{
		cout<<"Cannot Perform Delete Operation LL Empty!!"<<endl;
		return;
	}

	if(pos<0 && pos>size)
	{
		cout<<"Invalid Position!!"<<endl;
		return;
	}
	if(pos == 1)
	{
		DeleteFirst();
	}
	else if(pos == size)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp = head;
	
		for(int iCnt = 1; iCnt< pos-1; iCnt++)
		{
			temp = temp->next;
		}

		PNODE tempdelete = temp->next;	
		temp->next->next->prev = temp;
		temp->next = temp->next->next;
		
		delete tempdelete;
		iCnt--;
	}
	
} 

void DoublyCircular_LL::Display()
{
	PNODE temp = NULL;
	temp = head;

	do
	{
		cout<<"<-|"<<temp->data<<"|->";
		temp = temp->next;
	}
	while(temp != head);
	cout<<endl;
}

int DoublyCircular_LL::Count()
{
	return iCnt;
}
void DoublyCircular_LL::Head_Tail()
{
	cout<<"Head : "<<head->data<<endl;
	cout<<"Tail : "<<tail->data<<endl;
}

int main()
{

	PNODE first = NULL;

	DoublyCircular_LL obj;

	obj.InsertFirst(11);
	obj.InsertLast(24);
	obj.InsertAtPos(20,2);
	obj.InsertAtPos(1,1);
	obj.InsertAtPos(25,5);
	obj.DeleteAtPos(4);
	obj.Display();

	cout<<"No Of Nodes : "<<obj.Count()<<endl;
	obj.Head_Tail();

	return 0;
}