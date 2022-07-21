#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node * next;
};

template<class T>
class generic_SinglyCLL
{
	private:			// characteristics
		struct node<T> *head;
		struct node<T> *tail;
		int iCnt;

	public:			// Behaviours
		generic_SinglyCLL();
		void InsertFirst(T no);
		void InsertLast(T no);
		void InsertAtPos(T no,int pos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();	
		void HeadTail();
		int Count();
	
};

template<class T>
generic_SinglyCLL<T>:: generic_SinglyCLL()
{
	head = NULL;
	tail= NULL;
	iCnt = 0;	
}

template<class T>
void generic_SinglyCLL<T>::InsertFirst(T no)
{

	iCnt++;
	struct node<T> *newn = NULL;
	
	newn = new node<T>;

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

template<class T>
void generic_SinglyCLL<T>:: InsertLast(T no)
{
	iCnt++;
	struct node<T> *newn = NULL;
	struct node<T> *temp = NULL;
	
	newn = new node<T>;

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

template<class T>
void generic_SinglyCLL<T>:: InsertAtPos(T no,int pos)
{
	int iSize = Count();
 
	if((pos < 0) || (pos > iSize+1))
	{
		cout<<"INVALID POSITION!!"<<endl;
		return;
	}

	struct node<T> *newn = NULL;
	newn = new node<T>;

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
		struct node<T> *temp = head;

		for(i = 1; i < pos-1; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next = newn;
	}
	
 
}

template<class T>
void generic_SinglyCLL<T>:: DeleteFirst()
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

template<class T>
void generic_SinglyCLL<T>:: DeleteLast()
{
	if((head == NULL) && (tail == NULL))
	{
		return;
	}	
	iCnt--;

	struct node<T> *temp = head;

	while(temp->next != tail)
	{
		temp = temp->next;
	}

	delete(temp->next);
	temp->next = head;
	tail = temp;
}

template<class T>
void generic_SinglyCLL<T>:: DeleteAtPos(int pos)
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
		struct node<T> *temp = head;

		for(i = 1; i < pos-1 ; i++)
		{
			temp = temp->next;
		} 

		struct node<T> *tempdelete = temp->next;
		temp->next = tempdelete->next;
		delete tempdelete;
	}
	
}

template<class T>
void generic_SinglyCLL<T>:: Display()
{
	struct node<T> *temp = head;
	
	do
	{
		cout<<"<-|"<<temp->data<<"|->";
		temp = temp->next;
	}
	while(temp != head);	

	cout<<endl;
}

template<class T>
int generic_SinglyCLL<T>:: Count()
{
	return iCnt;
}

template<class T>
void generic_SinglyCLL<T>:: HeadTail()
{
	T Head, Tail;
	Head = head->data;
	Tail = tail->data;

	cout<<"HEAD : "<<Head<<endl;
	cout<<"TAIL : "<<Tail<<endl;
}


int main()
{
	generic_SinglyCLL<int> obj;

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

    cout<<"-----------------------------------------------------------------------------"<<endl;

    generic_SinglyCLL<string>obj2;

    obj2.InsertLast("Generic");
    obj2.InsertFirst("is");
    obj2.InsertFirst("This");
    obj2.InsertLast("Program");
    obj2.InsertAtPos("The",3);

    obj2.Display();
    cout<<"No Of Element In LL Are : "<<obj2.Count()<<endl;

    obj2.DeleteAtPos(3);

    obj2.Display();
    cout<<"No Of Element In LL Are : "<<obj2.Count()<<endl;
	obj2.HeadTail();



	return 0;
}