#include<iostream>
using namespace std;


struct node
{
   int data;
   struct node *next;   
};

typedef struct node NODE;
typedef struct node *PNODE;

class Queue
{
	public:
	PNODE head;
	int Count;
	
	Queue(); //constructor
	void Enqueue(int); //InsertLast
	void Dequeue();  //DeleteFirst
	void Display();
	int CountNode();
};

    Queue::Queue() //constructor
	{
		head=NULL;
		Count=0;
	}
	
	void Queue::Enqueue(int no)	//InsertLast
	{
		PNODE newn=NULL;
		newn=new NODE;
		
		newn->data=no;
		newn->next=NULL;
		
		if(head==NULL)
		{
			head=newn;
		}
		else
		{
			PNODE temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
		}
		Count++;
	}
	
	void Queue::Dequeue()  //DeleteFirst
	{
		int no;
		if(Count==0)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
		no=head->data;
		PNODE temp=head;
		head=head->next;
		delete temp;
		Count--;
		cout<<"Removed element is :"<<no<<endl;
	}
	
	void Queue::Display()
	{
		cout<<"Elements from Queue are:"<<endl;
		PNODE temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	int Queue::CountNode()
	{
		return Count;
	}

int main()
{
	Queue obj;
	obj.Enqueue(11);
	obj.Enqueue(12);
	obj.Enqueue(13);
	obj.Enqueue(14);
	obj.Dequeue();
	obj.Display();
	return 0;
}
	