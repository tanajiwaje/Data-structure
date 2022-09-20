#include<iostream>
using namespace std;

template<class T>
struct node
{
   T data;
   struct node *next;   
};

template<class T>
class Queue
{
	public:
	struct node<T> *head;
	int Count;
	
	Queue(); //constructor
	void Enqueue(T); //InsertLast
    void Dequeue();  //DeleteFirst
	void Display();
	int CountNode();
};
    template<class T>
    Queue<T>::Queue() //constructor
	{
		head=NULL;
		Count=0;
	}
	
	template<class T>
	void Queue<T>::Enqueue(T no)	//InsertLast
	{
		struct node<T> *newn=NULL;
		newn=new struct node<T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if(head==NULL)
		{
			head=newn;
		}
		else
		{
			struct node<T> *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
		}
		Count++;
	}
	 
	template<class T>
	void Queue<T>::Dequeue()  //DeleteFirst
	{
		T no;
		if(Count==0)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
		no=head->data;
		struct node<T> *temp=head;
		head=head->next;
		delete temp;
		Count--;
		cout<<"Removed element is :"<<no<<endl;
	}
	
	template<class T>
	void Queue<T>::Display()
	{
		cout<<"Elements from Queue are:"<<endl;
		struct node<T> *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	template<class T>
	int Queue<T>::CountNode()
	{
		return Count;
	}
	
	
int main()
{
	Queue<int> obj;
	obj.Enqueue(11);
	obj.Enqueue(12);
	obj.Enqueue(13);
	obj.Enqueue(14);
	obj.Display();
	obj.Dequeue();
	obj.Display();
	return 0;
}
	