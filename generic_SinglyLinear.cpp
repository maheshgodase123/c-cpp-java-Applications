#include<iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
	
};

//we cannot write typedef bcoz template does not allow typedef

template<class T>
class SinglyLL
{
	private:
		struct node<T> *head;
		int cnt;

	public:
		SinglyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void DeleteFirst();
		void DeleteLast();
		void InsertAtPos(T,int);
		void DeleteAtPos(int);
		void Display();
		int CountNode();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
	head = 0;
	cnt = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;	 //creating newn pointer
	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		newn->next = head;
		head = newn;
	}
	cnt++;

}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		struct node<T> *temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
	}
	cnt++;

}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
	if(head == NULL)
	{
		cout<<"LL is Empty Cannot Perform Operation!!!"<<endl;
		return;
	}
	else
	{
		struct node<T> *temp = head;
		head = head->next;
		delete temp;
	}

	cnt--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
	if(head == NULL)
	{
		cout<<"LL is Empty Cannot Perform Operation!!!"<<endl;
		return;
	}
	else if(head->next == NULL)
	{
		delete head;
		head = NULL;

		cnt--;	
	}
	else
	{
		struct node<T> *temp = head;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		delete temp->next;
		temp->next = NULL;
	}
	cnt--;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T no, int pos)
{
	if(pos < 0 || pos > (cnt+1))
	{
		cout<<"Inavalid Position!!"<<endl;
		return;
	}

	if(pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos == (cnt+1))
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> *newn = NULL;
	
		newn = new node<T>;

		newn->data = no;
		newn->next = NULL;

		struct node<T> *temp = head;
		for(int i= 1; i < pos-1; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;	
		temp->next = newn; 
	
		cnt++;
	}

}

template<class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
	if(pos < 0 || pos > cnt)
	{
		cout<<"Inavalid Position!!"<<endl;
		return;
	}

	if(pos == 1)
	{
		DeleteFirst();
	}
	else if(pos == cnt)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *tempdelete = NULL;
		
		struct node<T> *temp = head;
		for(int i= 1; i < pos-1; i++)
		{
			temp = temp->next;
		}

		tempdelete = temp->next;
		temp->next = temp->next->next;	
		delete tempdelete; 
	
		cnt--;
	}

}

template<class T>
void SinglyLL<T>::Display()
{
	cout<<"Element In Linked List : "<<endl;

	struct node<T> *temp = head;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
template<class T>
int SinglyLL<T>::CountNode()
{
	return cnt;
}


int main()
{
	SinglyLL<int>obj;
	
	obj.InsertFirst(5);
	obj.InsertLast(8);	
	obj.InsertAtPos(10,2);
	obj.InsertAtPos(15,4);
	obj.InsertAtPos(30,5);
	obj.InsertAtPos(20,5);
	obj.DeleteFirst();
	obj.DeleteAtPos(1);

	obj.Display();
	cout<<"No of Nodes Are : "<<obj.CountNode()<<endl;

	cout<<"Entering String Type"<<endl;

	SinglyLL<string>obj2;
	
	obj2.InsertFirst("Mahesh");	
	obj2.InsertLast("Ankush");
	obj2.InsertAtPos("Godase",2);
	obj2.DeleteFirst();
	obj2.DeleteAtPos(2);

	obj2.Display();
	cout<<"No of Node Are : "<<obj2.CountNode()<<endl;

	return 0;
}