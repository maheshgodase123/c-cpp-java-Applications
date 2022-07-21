#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLinear
{
    private:
        PNODE head;
        int Count;

    public:
        SinglyLinear();
        void InsertFirst(int);
        void InsertLast(int);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int,int);
        void DeleteAtPos(int);
        int CountNode();
        void Display();

};

SinglyLinear:: SinglyLinear()
{
    head = NULL;
    Count = 0;
}

void SinglyLinear::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(head == 0 && Count == 0)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    Count++;
}

void SinglyLinear::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(head == 0 && Count == 0)
    {
        head = newn;
    }
    else if(Count == 1 && head->next == NULL)
    {
        head->next = newn;
    }
    else
    {
        PNODE temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    Count++;
}

void SinglyLinear::DeleteFirst()
{
    if(head == 0 && Count == 0)
    {
        cout<<"Cannot Perform Delete Operation!!"<<endl;
        return;
    }
    else
    {
        PNODE tempDelete = head;
        head = head->next;
        delete tempDelete;
    }
    Count--;
}

void SinglyLinear::DeleteLast()
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
        PNODE temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next; 
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

void SinglyLinear::InsertAtPos(int no, int pos)
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
        PNODE newn = NULL;
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        PNODE temp = head;
        for(int i=1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}

void SinglyLinear::DeleteAtPos(int pos)
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
        PNODE temp = head;
        for(int i=1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        PNODE tempDelete = temp->next;
        temp->next = temp->next->next;
    }
    Count--;
}

int SinglyLinear::CountNode()
{
    return Count;
}

void SinglyLinear::Display()
{
    cout<<"Element In The LL Are : "<<endl;
    PNODE temp = head;
    while(temp!= NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{

    SinglyLinear obj;

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

    return 0;
}