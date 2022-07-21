#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCLL
{
	private:			// characteristics
		PNODE head;
		PNODE tail;
		int iCnt;

	public:			// Behaviours
		SinglyCLL();
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no,int pos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();	
		void HeadTail();
		int Count();
	
};


SinglyCLL:: SinglyCLL()
{
	head = NULL;
	tail= NULL;	// 16 byte is assign bcoz 1 data and 2 pointers(head,tail)
	iCnt = 0;	
}

void SinglyCLL::InsertFirst(int no)
{

	iCnt++;
	PNODE newn = NULL;
	
	newn = new NODE;

	if(newn == NULL)
	{
		return;
	}

	newn->data = no;
	newn->next = NULL;

	if((head == NULL) && (tail == NULL))	//if cll is empty
	{
		head = newn;
		tail = newn;
	} 
	else							//if cll contains atleast one node
	{
		newn->next = head;
		head = newn;
	}

	tail->next = head;	// this is most important and will not give error if written anywhere
}

void SinglyCLL:: InsertLast(int no)
{
	iCnt++;
	PNODE newn = NULL;
	PNODE temp = NULL;
	
	newn = new NODE;

	if(newn == NULL)
	{
		return;
	}

	newn->data = no;
	newn->next = NULL;

	if((head == NULL) && (tail == NULL))	//if cll is empty
	{
		head = newn;
		tail = newn;
	} 
	else							//if cll contains atleast one node
	{
		tail->next = newn;
		tail = newn;	
	}

	tail->next = head;
}

void SinglyCLL:: InsertAtPos(int no,int pos)
{
	int iSize = Count();
 
	if((pos < 0) || (pos > iSize+1))
	{
		cout<<"INVALID POSITION!!"<<endl;
		return;
	}

	PNODE newn = NULL;
	newn = new NODE;

	if(newn == NULL)
	{
		return;
	}

	newn->data = no;
	newn->next = NULL;

	if(pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos == iSize+1)
	{
		InsertLast(no);
	}
	else
	{
		iCnt++;
		int i = 0;
		PNODE temp = head;

		for(i = 1; i < pos-1; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next = newn;
	}
	
 
}

void SinglyCLL:: DeleteFirst()
{
	if((head == NULL) && (tail == NULL))
	{
		return;	 
	}
	iCnt--;

	head = head->next;
	delete tail->next;
	tail->next = head;
}

void SinglyCLL:: DeleteLast()
{
	if((head == NULL) && (tail == NULL))
	{
		return;
	}	
	iCnt--;

	PNODE temp = head;

	while(temp->next != tail)
	{
		temp = temp->next;
	}

	delete(temp->next);
	temp->next = head;
	tail = temp;
}

void SinglyCLL:: DeleteAtPos(int pos)
{
	int iSize = Count();
 
	if((pos < 0) || (pos > iSize))
	{
		cout<<"INVALID POSITION!!"<<endl;
		return;
	}

	if(pos == 1)
	{
		DeleteFirst();
	}
	else if(pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		iCnt--;

		int i = 0;
		PNODE temp = head;

		for(i = 1; i < pos-1 ; i++)
		{
			temp = temp->next;
		} 

		PNODE tempdelete = temp->next;
		temp->next = tempdelete->next;
		delete tempdelete;
	}
	
}

void SinglyCLL:: Display()
{
	PNODE temp = head;
	
	do
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	while(temp != head);	// to know why we use do-while make it while loop and then run u will get it

	cout<<endl;
}

int SinglyCLL:: Count()
{
	return iCnt;
}

void SinglyCLL:: HeadTail()
{
	int Head, Tail;
	Head = head->data;
	Tail = tail->data;

	cout<<"HEAD : "<<Head<<endl;
	cout<<"TAIL : "<<Tail<<endl;
}


int main()
{
	SinglyCLL obj;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(101);
	obj.InsertLast(111);

	obj.InsertAtPos(61,4);
	obj.DeleteAtPos(4);

	obj.Display();
	obj.HeadTail();

	cout<<"Count Is : "<<obj.Count()<<endl;

	return 0;
}