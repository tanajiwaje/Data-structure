#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyCLL
{
	private:
	PNODE head;
	PNODE tail;
	public:
	SinglyCLL();
	void InsertFirst(int no);
	void InsertLast(int no);
	void InsertAtPos(int no,int pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int pos);
	void Display();
	int Count();
	
};

   SinglyCLL::SinglyCLL()
   {
	 head=NULL;
	 tail=NULL; 
   }
   
   void SinglyCLL::InsertFirst(int no)
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
   
   void SinglyCLL::InsertLast(int no)
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
		   tail->next=newn;
		   tail=newn;
	   }
	   tail->next=head;
	   
   }
   
   void SinglyCLL::InsertAtPos(int no,int pos)
   {
	   int size=Count();
	   
	   if((pos<1) || (pos>size+1))
	   {
		   cout<<"Invalid position";
		   return;
	   }
	   
	   if(pos==1)
	   {
		  InsertFirst(no);
	   }
	   else if(pos==size+1)
	   {
		   InsertLast(no);
	   }
	   else
	   {
		   PNODE newn=NULL;
		   newn=new NODE;
		   newn->data=no;
		   newn->next=NULL;
		    
		   PNODE temp=head;
		   int iCnt=0;
		   for(iCnt=1;iCnt<pos-1;iCnt++)
		   {
			   temp=temp->next;
			   
		   }
		   newn->next=temp->next;
		   temp->next=newn;
	   }
   }
   
   void SinglyCLL::DeleteFirst()
   {
	   if((head==NULL) && (tail==NULL))
	   {
		   return;
	   }
	   else if(head==tail)
	   {
		   delete head;
		   head=NULL;
		   tail=NULL;
	   }
	   else
	   {
		   head=head->next;
		   delete tail->next;
		   tail->next=head;
	   }
   }
   
   void SinglyCLL::DeleteLast()
   {
	   if((head==NULL) && (tail==NULL))
	   {
		   return;
	   }
	   else if(head==tail)
	   {
		   delete tail;
		   head=NULL;
		   tail=NULL;
	   }
	   else
	   {
		   PNODE temp=head;
		   while(temp->next!=tail)
		   {
			   temp=temp->next;
			   
		   }
		   delete tail;
		   tail=temp;
		   tail->next=head;

		 
	   }
   
   }
  
   void SinglyCLL::DeleteAtPos(int pos)
   {
	   int size=Count();
	   
	   if((pos<1)|| (pos>size))
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
		   PNODE temp1=head;
		   int iCnt=0;
		   
		   for(iCnt=1;iCnt<pos-1;iCnt++)
		   {
			   temp1=temp1->next;
		   }
		   
		   PNODE temp2=temp1->next;
		   
		   temp1->next=temp2->next;
		   delete temp2;
	   }
   }
   
   void SinglyCLL::Display()
   {
	   PNODE temp=head;
	   if((head==NULL) && (tail==NULL))
	   {
		   return;
	   }
	   do
	   {
		   cout<<temp->data<<"\n";
		   temp=temp->next;
		}while(temp!=head);
		cout<<endl;
   }
   
   int SinglyCLL::Count()
   {
	   int iCnt=0;
	   PNODE temp=head;
	   
	   if((head==NULL) && (tail==NULL))
	   {
		   return 0;
	   }
	   
	   do
	   {
		   iCnt++;
		   temp=temp->next;
		   
	   }while(temp!=head);
	   return iCnt;
   }
   
int main()
{
	SinglyCLL obj;
	obj.InsertFirst(10);
	obj.InsertFirst(11);
	obj.InsertFirst(12);
	obj.InsertFirst(13);
	obj.InsertLast(12);
	obj.InsertLast(13);
	obj.InsertLast(14);
	obj.InsertAtPos(1111,5);
	obj.DeleteFirst();
	obj.DeleteFirst();
	obj.InsertFirst(10);
	obj.DeleteAtPos(3);
	obj.Display();
	return 0;
}