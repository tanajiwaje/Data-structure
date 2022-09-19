#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Doubley
{
	public:
	PNODE head;
	Doubley();
	void InsertFirst(int no);
	void InsertLast(int);
	void InsertAtPos(int no,int pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int pos);
	void Display();
	int Count();
};

    Doubley::Doubley()
	{ 
	   head=NULL;
	}
	void Doubley::InsertFirst(int no)
	{
		PNODE newn=NULL;
		newn=new NODE;
		
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		if(head==NULL)
		{
			head=newn;
		}
		else
		{
			newn->next=head;
			head->prev=newn;
			head=newn;
		}
		
	}
	void Doubley::InsertLast(int no)
	{
		PNODE newn=NULL;
		newn=new NODE;
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		if(head==NULL)
		{
			head=newn;
		}
		else
		{
			PNODE temp=NULL;
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
			newn->prev=temp;	
		}
		
	}
	
	int Doubley::Count()
	{
		int iCtnt=0;
	    PNODE temp=head;
		
		while(temp!=NULL)
		{
			int iCnt=0;
			while(temp!=NULL)
			{
				iCnt++;
				temp=temp->next;
			}
			return iCnt;	
		}
	}
	
	void Doubley::InsertAtPos(int no,int pos)
	{
		int size=Count();
		if((pos<1)|| (pos>size+1))
		{
			cout<<"Invalid position";
			return;
		}
		if(pos==1)
		{
			InsertFirst(no);
		}
		else if(pos==(size+1))
		{
			InsertLast(no);
		}
		else
		{
			PNODE newn=NULL;
			newn=new NODE;
			newn->data=no;
			newn->next=NULL;
			newn->prev=NULL;
			
			PNODE temp=head;
			int iCnt=0;
			for(iCnt=1;iCnt<(pos-1);iCnt++)
			{
				temp=temp->next;
			}
			
			newn->next=temp->next;
			temp->next->prev=newn;
			temp->next=newn;
			temp->next->prev=temp;
		}
	}
	
	void Doubley::DeleteFirst()
	{
		if(head==NULL) 
		{
			printf("invalid position");
			return;
		}
		
		if((head)->next==NULL)
		{
			delete(head);
			head=NULL;
		}
		else
		{
			head=head->next;
			delete ((head)->prev);
			head->prev=NULL;
		}
	}
	
	void Doubley::DeleteLast()
	{
		PNODE temp;
		if(head==NULL)
		{
			return;
		}
		if((head)->next==NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			temp=head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			free(temp->next);
			temp->next=NULL;
		}
			
	}
	
	void Doubley::DeleteAtPos(int pos)
	{
		PNODE temp=NULL;
		int size=0;
		size=Count();
		if((pos<1) || (pos>size))
		{
			cout<<"Invalid position";
			return;
		}
		if(pos==1)
		{
			DeleteFirst();
		}
		else if(pos==size)
		{
			DeleteLast();
		}
		else
		{
			temp=head;
			int iCnt=0;
			for(iCnt=1;iCnt<(pos-1);iCnt++)
			{
				temp=temp->next;
			}
			temp->next=temp->next->next;
			delete (temp->next->prev);
			temp->next->prev=temp;
		}
		
	}
	
	void Doubley::Display()
	{
		PNODE temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\n";
			temp=temp->next;
		}
	}


int main()
{
	Doubley dobj;
	dobj.InsertFirst(10);
	dobj.InsertFirst(20);
	dobj.InsertFirst(30);
	dobj.InsertFirst(40);
	dobj.InsertFirst(50);
	dobj.Display();  
	int ret=dobj.Count();
	cout<<"Count of an number is:"<<ret<<"\n";
	dobj.InsertAtPos(100,0);
	dobj.DeleteLast();
	dobj.DeleteFirst();
	dobj.DeleteAtPos(2);
	dobj.Display(); 
	
	return 0;
}


