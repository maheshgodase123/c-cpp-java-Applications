#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Stack
{
    public:
        struct node<T> *Head;
        int Count;

        Stack();
        void Push(T);        // InsertLast
        void Pop();          // DeleteFirst
        void Display();
        int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    
    newn->next = Head;		// it will work for both condition
    Head = newn;
    Count++;
}

template<class T>
void Stack<T>::Pop()	//DeleteFirst
{
      T no;

	if(Head == NULL)
	{
		cout<<"Stack is empty"<<endl;
		return;
	}
	
	no = Head->data;
	struct node<T> *temp = Head;
	Head = Head->next;
	delete temp;

	Count--;
	cout<<"Removed Element Is :"<<no<<endl;
}

template<class T>
void Stack<T>::Display()
{
    cout<<"Elements from Stack are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

int main()
{
	Stack<char>obj1;

	obj1.Push('A');
	obj1.Push('B');
	obj1.Push('C');
	obj1.Push('D');
	
	obj1.Display();
	cout<<"Elements Are : "<<obj1.CountNode()<<endl;

	obj1.Pop();
	obj1.Pop();
	
	obj1.Push('Z');
	obj1.Display();
	cout<<"Elements Are : "<<obj1.CountNode()<<endl;
	
	obj1.Pop();

	obj1.Display();
	cout<<"Elements Are : "<<obj1.CountNode()<<endl;
	return 0;
}