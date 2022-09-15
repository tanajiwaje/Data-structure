#include<iostream>
using namespace std;

struct node 
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Singley
{
	private:
	PNODE head;
	public:
	Singley();
	void InsertFirst(int no);
	void InsertLast(int no);
	void InsertAtPos(int no,int pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos();
	void Display();
	int Count();
	
};

    Singley::Singley()
	{
		head=NULL;
	}
	void Singley::InsertFirst(int no)
	{
		PNODE newn=NULL;
     	newn=new NODE;
	    if(!newn)
		  printf("error \n");
    	newn->data=no;
     	newn->next=NULL;
	
	    if(head==NULL)
        {
		  head=newn;
	    }
	    else
	    {
		   newn->next=head;
		   head=newn;
	    }
	}
	void Singley::InsertLast(int no)
	{
		PNODE newn=NULL;
	    newn=(PNODE)malloc(sizeof(NODE));
 	    newn->data=no;
	    newn->next=NULL;
	
	    if(head==NULL) //check whether first node contain another node or not
      	{
		   head=newn; //if node is empty then newn is the first node of that linked list 
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
	    }
	}
	void Singley::InsertAtPos(int no,int pos)
	{
		int size=Count();
	    if((pos<1) || pos>(size+1))
	    {
		    printf("Invalid position");
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
		   newn=(PNODE)malloc(sizeof(NODE));
		   newn->data=no;
		   newn->next=NULL;
		
		   PNODE temp=NULL;
		   temp=head;
	       int iCnt=0;
		   for(iCnt=1;iCnt<pos-1;iCnt++)
		   {
			  temp=temp->next;
		   }
		   newn->next=temp->next;
		   temp->next=newn;
	 }
	}
	
	void Singley::DeleteFirst()
	{
		if((head)==NULL)
	    {
		  return;
	    }
        else
      	{
		  PNODE temp=NULL;
		  temp=head;
		  head=temp->next;
		  free(temp);
	   }
	}
	
	void Singley::DeleteLast()
	{
		if(head==NULL)
	    {
		  return;
	    }
	    else
	    {
		   PNODE temp=NULL;
	       temp=head;
		   while(temp->next->next!=NULL)
		   {
			  temp=temp->next;
		   }
		   free(temp->next);
		   temp->next=NULL;
	    }
		
	}
	void Singley::DeleteAtPos(int pos)
	{
		int size=Count();
	    int iCnt=0;
	    if(pos<0 || pos>size)
	    {
		  printf("Invaid Position");
		  return;
	    }
	    if(pos==1)
	    {
		  DeleteFirst();
		
	    }
	    else if(pos==(size))
    	{
	    	DeleteLast();
    	}
	    else
	    {
		   PNODE temp=head;
		   for(iCnt=1;iCnt<pos-1;iCnt++)
		   {
			  temp=temp->next;
		   }
		   PNODE tempdelete=NULL;
		   tempdelete=temp->next;
		   temp->next=temp->next->next;
		   free(tempdelete);
	    }
	}
	void Singley::Display()
	{
		PNODE temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	int Singley::Count()
	{
		int iCnt=0;
	    PNODE temp=head;
	  while(temp!=NULL)
	    {
	      iCnt++;	
		  temp=temp->next;
	    }
	     return iCnt;
	}

int main()
{
	Singley obj;
	obj.InsertFirst(3);
	obj.InsertFirst(4);
	obj.InsertFirst(5);
	obj.InsertFirst(6);
	//obj.Display();
	obj.InsertLast(7);
	obj.InsertAtPos(56,4);
	//obj.Display();
	obj.DeleteFirst();
	obj.Display();
	int iRet=obj.Count();
	cout<<"iREt is "<<iRet;
	return 0;
}