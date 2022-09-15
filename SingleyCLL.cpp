#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class SingleyCLL
{
	private:
	  PNODE head;
	  PNODE tail;
	public:
	 SingleyCLL();
	 void InsertFirst(int no);
	 void InsertLast(int no);
	 void InsertAtPos(int no,int pos);
	 void DeleteFirst();
	 void DeleteLast();
	 void DeleteAtPos();
	 int Count();
	 void Display();
};

     SingleyCLL::SingleyCLL()
	 {
		 head=NULL;
		 tail=NULL;
	 }
	 void SingleyCLL::InsertFirst(int no)
	 {
		PNODE newn=NULL;
		newn=new NODE;
		newn->data=no;
		newn->next=NULL;
		
		if((head==NULL) && (tail==NULL))
		{
			head=newn;
			tail=newn;
		}
		else
		{
			newn->next=head;
			head=newn;
			
		}
		tail->next=head;
		
	 }
	 void SingleyCLL::InsertLast(int no)
	 {}
	 void SingleyCLL::InsertAtPos(int no,int pos)
	 {}
	 void SingleyCLL::DeleteFirst()
	 {}
	 void SingleyCLL::DeleteLast()
	 {}
	 void SingleyCLL::DeleteAtPos()
	 {}
	 int SingleyCLL::Count()
	 {}
	 void SingleyCLL::Display()
	 {
		 PNODE temp=head;
		 if((head==NULL) && (tail==NULL))
		 {
			 return;
		 }
		 do
		 {
			 cout<<temp->data;
			 temp=temp->next;
		 }while(temp!=head);
		 
		 
	 }

int main()
{
	SingleyCLL obj;
	obj.InsertFirst(4);
	obj.InsertFirst(5);
	obj.InsertFirst(6);
	obj.InsertFirst(7);
	obj.Display();
	return 0;
}