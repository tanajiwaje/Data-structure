#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Stack
{
    private:
	PNODE head;
	int Count;
	public:
	Stack();
	void push(int);
	void pop();
	void Display();
	int CountNode();
};

  Stack::Stack()
  {
	  head=NULL;
	  Count=0;
  }
  
   void Stack::push(int no)
   {
	   PNODE newn=NULL;
	   newn=new NODE;
	   newn->data=no;
	   newn->next=NULL;
	   
	   newn->next=head;
	   head=newn;
	   Count++;
	   
   }
   void Stack::pop()
   {
	   int no;
	   if(Count==0)
	   {
		   cout<<"Stack is empty";
		   return;
	   }
	   no=head->data;
	   PNODE temp=head;
	   head=head->next;
	   delete temp;
	   Count--;
	   cout<<"Removed elements is:"<<no<<endl;

   }
   void Stack::Display()
   {
	   cout<<"Elements from stack are:"<<endl;
	   PNODE temp=head;
	   while(temp!=NULL)
	   {
		   cout<<temp->data<<" ";
		   temp=temp->next;
	   }
	   cout<<endl;
   }
   int Stack::CountNode()
   {
	   return Count;
   }
  
int main()
{
	Stack obj;
	obj.push(10);
	obj.push(40);
	obj.push(30);
	obj.push(50);
	obj.push(80);
	obj.Display();
	obj.pop();
	obj.Display();
	obj.pop();
	obj.Display();
}

