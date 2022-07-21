#include<iostream>

using namespace std;

template<class T>
struct node{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class generic_DoublyLinear
{
    private:
        struct node<T> *head;
        int Count;

    public:

        generic_DoublyLinear();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
        int CountNode();
        void Display();
};

template<class T>
generic_DoublyLinear<T>:: generic_DoublyLinear()
{
    head = NULL;
    Count = 0;
}

template<class T>
void generic_DoublyLinear<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == 0 && Count == 0)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    Count++;
}

template<class T>
void generic_DoublyLinear<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == 0 && Count == 0)
    {
        head = newn;
    }
    else if(Count == 1 && head->next == NULL)
    {
        head->next = newn;
        newn->prev = head;
    }
    else
    {
        struct node<T> *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}

template<class T>
void generic_DoublyLinear<T>::DeleteFirst()
{
    if(head == 0 && Count == 0)
    {
        cout<<"Cannot Perform Delete Operation!!"<<endl;
        return;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
    Count--;
}

template<class T>
void generic_DoublyLinear<T>::DeleteLast()
{
    if(head == 0 && Count == 0)
    {
        cout<<"Cannot Perform Delete Operation!!"<<endl;
        return;
    }
    else if(Count == 1 && head->next == NULL)
    {
        delete head->next;
        head->next = NULL;
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
    Count--;
}

template<class T>
void generic_DoublyLinear<T>::InsertAtPos(T no, int pos)
{
    if(pos < 0 || pos > (Count+1))
    {
        cout<<"Invalid Position!!"<<endl;
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == (Count+1))
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
        for(int i=1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        Count++;
    }
}

template<class T>
void generic_DoublyLinear<T>::DeleteAtPos(int pos)
{
     if(pos < 0 || pos > (Count))
    {
        cout<<"Invalid Position!!"<<endl;
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == (Count+1))
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = head;
        for(int i=1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        struct node<T> *tempDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete tempDelete;
    }
    Count--;
}

template<class T>
int generic_DoublyLinear<T>::CountNode()
{
    return Count;
}

template<class T>
void generic_DoublyLinear<T>::Display()
{
    cout<<"Element In The LL Are : "<<endl;
    struct node<T> *temp = head;
    cout<<"NULL";
    while(temp!= NULL)
    {
        cout<<"<-|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


int main()
{
    generic_DoublyLinear<int>obj;

    obj.InsertLast(41);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(51);
    obj.InsertAtPos(31,3);

    obj.Display();
    cout<<"No Of Element In LL Are : "<<obj.CountNode()<<endl;

    obj.DeleteAtPos(3);

    obj.Display();
    cout<<"No Of Element In LL Are : "<<obj.CountNode()<<endl;

    cout<<"------------------------------------------------------------------------------"<<endl;

    generic_DoublyLinear<string>obj2;

    obj2.InsertLast("Generic");
    obj2.InsertFirst("is");
    obj2.InsertFirst("This");
    obj2.InsertLast("Program");
    obj2.InsertAtPos("The",3);

    obj2.Display();
    cout<<"No Of Element In LL Are : "<<obj2.CountNode()<<endl;

    obj2.DeleteAtPos(3);

    obj2.Display();
    cout<<"No Of Element In LL Are : "<<obj2.CountNode()<<endl;

    return 0;
}