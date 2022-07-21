#include<iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	int iCnt;
	struct node *next;
	struct node *prev;
};

template<class T>
class generic_DoublyCircular
{

	private:
		struct node<T> *head;
		struct node<T> *tail;
		int iCnt;

	public:

		generic_DoublyCircular();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T, int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		inline int Count();
		inline void Display();
		void Head_Tail();
};

template<class T>
generic_DoublyCircular<T>:: generic_DoublyCircular()
{
	head = NULL;
	tail = NULL;
	iCnt = 0;
}

template<class T>
void generic_DoublyCircular<T>:: InsertFirst(T no)
{
	struct node<T> *newn = NULL;

	newn = new node<T>;

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

template<class T>
void generic_DoublyCircular<T>:: InsertLast(T no)
{
	struct node<T> *newn = NULL;

	newn = new node<T>;
	
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

template<class T>
void generic_DoublyCircular<T>::InsertAtPos(T no, int pos)
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
		struct node<T> *newn = NULL;
	
		newn = new node<T>;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		struct node<T> *temp = head;
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

template<class T>
void generic_DoublyCircular<T>::DeleteFirst()
{
	if(head == NULL && tail == NULL)
	{
		cout<<"Cannot Perform Delete Operation LL Empty!!"<<endl;
		return;
	}
	struct node<T> *temp = head;
	
	head = head->next;
	head->prev = tail;
	tail->next = head;
	delete temp;
	iCnt--;
}

template<class T>
void generic_DoublyCircular<T>::DeleteLast()
{
	if(head == NULL && tail == NULL)
	{
		cout<<"Cannot Perform Delete Operation LL Empty!!"<<endl;
		return;
	}
	
	struct node<T> *temp = tail;	
	tail = tail->prev;
	tail->next = head;
	head->prev = tail;

	delete temp;

	iCnt--;
}

template<class T>
void generic_DoublyCircular<T>::DeleteAtPos(int pos)
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
		struct node<T> *temp = head;
	
		for(int iCnt = 1; iCnt< pos-1; iCnt++)
		{
			temp = temp->next;
		}

		struct node<T> *tempdelete = temp->next;	
		temp->next->next->prev = temp;
		temp->next = temp->next->next;
		
		delete tempdelete;
		iCnt--;
	}
	
} 

template<class T>
void generic_DoublyCircular<T>::Display()
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
int generic_DoublyCircular<T>::Count()
{
	return iCnt;
}

template<class T>
void generic_DoublyCircular<T>::Head_Tail()
{
	cout<<"Head : "<<head->data<<endl;
	cout<<"Tail : "<<tail->data<<endl;
}

int main()
{
	generic_DoublyCircular<int> obj;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(101);
	obj.InsertLast(111);

	obj.InsertAtPos(61,4);
	obj.DeleteAtPos(4);

	obj.Display();
	obj.Head_Tail();

	cout<<"Count Is : "<<obj.Count()<<endl;

    cout<<"-----------------------------------------------------------------------------"<<endl;

    generic_DoublyCircular<string>obj2;

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
	obj2.Head_Tail();


	return 0;
}