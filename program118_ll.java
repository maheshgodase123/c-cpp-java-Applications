import java.lang.*;
import java.util.*;

class node		// same like struct node
{
	public int data;
	public node next;
}

class SinglyLL
{
	private node head;
	private int Count;

	public SinglyLL()
	{
		head = null;
		Count = 0;
	}

	public void InsertFirst(int no)
	{
		node newn = new node();

		newn.data = no;
		newn.next = null;

		if(head == null)
		{
			head = newn;
		}
		else
		{
			newn.next = head;
			head = newn;
		}

		Count++;
	}

	public void InsertLast(int no)
	{
		node newn = new node();

		newn.data = no;
		newn.next = null;

		if(head == null)
		{
			head = newn;
		}
		else
		{
			node temp = head;
	
			while(temp.next != null)
			{
				temp = temp.next;
			}

			temp.next = newn;
		}

		Count++;
	}

	public void Display()
	{
		node temp = head;

		System.out.println("Elements of Linked List Are : ");

		while(temp != null)
		{
			System.out.print("|"+temp.data+"|->");
			temp = temp.next;
		}
		System.out.println("NULL");
	}

	public int CountNode()
	{
		return Count;
	}

	public void DeleteFirst()
	{
		if(Count == 0)
		{
			return;
		}
		else if(Count == 1)
		{
			head = null;
		}
		else
		{
			node temp = head;
			head = head.next;
			temp = null;
		}
		Count--;
	}

	public void DeleteLast()
	{
		if(Count == 0)
		{
			return;
		}
		else if(Count == 1)
		{
			head = null;
		}
		else
		{
			node temp = head;
			while(temp.next.next != null)
			{
				temp = temp.next;
			}

			temp.next = null;
		}
		Count--;
	}

	public void InsertAtPos(int no, int pos)
	{
		if(pos < 0 || pos > (Count+1))
		{
			System.out.println("Invalid Position");
			return;
		}
		else if(pos == 1)
		{
			InsertFirst(no);
		}
		else if(pos == Count+1)
		{
			InsertLast(no);
		}
		else
		{
			node newn = new node();
			newn.data = no;
			newn.next = null;

			node temp = head;
		
			for(int i = 1; i < pos-1;i++)
			{
				temp = temp.next;
			}

			newn.next = temp.next;
			temp.next = newn;

		Count++;
		}
	}

	public void DeleteAtPos(int pos)
	{
		if(pos < 0 || pos > Count)
		{
			System.out.println("Invalid Position");
			return;
		}
		else if(pos == 1)
		{
			DeleteFirst();
		}
		else if(pos == Count+1)
		{
			DeleteLast();
		}
		else
		{
			node temp = head;
		
			for(int i = 1; i < pos-1;i++)
			{
				temp = temp.next;
			}

			node tempdelete = temp.next;
			temp.next = temp.next.next;
			tempdelete = null;

		Count--;
		}
	}
}

class program118_ll
{
	public static void main(String[] args)
	{
		SinglyLL obj = new SinglyLL();

		obj.InsertFirst(51);
		obj.InsertFirst(21);
		obj.InsertFirst(11);

		obj.InsertLast(101);
		obj.InsertLast(111);

		obj.InsertAtPos(55,4);

		obj.Display();
		System.out.println("No Of Elements Are : "+ obj.CountNode());
	
		obj.DeleteFirst();
		obj.DeleteLast();
		obj.DeleteAtPos(4);
		

		obj.Display();
		System.out.println("No Of Elements Are : "+ obj.CountNode());

	}

}