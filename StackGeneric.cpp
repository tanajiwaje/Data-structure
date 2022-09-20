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
    private:
	struct node<T> *head;
	int Count;
	public:
	Stack();
	void push(T);
	void pop();
	void Display();
	int CountNode();
};
  template<class T>
  Stack<T>::Stack()
  {
	  head=NULL;
	  Count=0;
  }
  
  template<class T>
   void Stack<T>::push(T no)
   {
	   struct node<T> *newn=NULL;
	   newn=new struct node<T>;
	   newn->data=no;
	   newn->next=NULL;
	   
	   newn->next=head;
	   head=newn;
	   Count++;
	   
   }
   template<class T>
   void Stack<T>::pop()
   {
	   int no;
	   if(Count==0)
	   {
		   cout<<"Stack is empty";
		   return;
	   }
	   no=head->data;
	   struct node<T> *temp=head;
	   head=head->next;
	   delete temp;
	   Count--;
	   cout<<"Removed elements is:"<<no<<endl;

   }
   
   template<class T>
   void Stack<T>::Display()
   {
	   cout<<"Elements from stack are:"<<endl;
	   struct node<T> *temp=head;
	   while(temp!=NULL)
	   {
		   cout<<temp->data<<" ";
		   temp=temp->next;
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
	Stack<int> obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	
	obj.Display();
	obj.pop();
	obj.Display();
	obj.pop();
	obj.Display();
}

