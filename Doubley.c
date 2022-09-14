#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head,int no)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		newn->next=*head;
		(*head)->prev=newn;
		*head=newn;
	}
}

void InsertLast(PPNODE head,int no)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		PNODE temp=NULL;
        temp=*head;
	
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
	}
}

int Count(PNODE head)
{
	int iCnt=0;
	while(head!=NULL)
	{
		iCnt++;
		head=head->next;
	}
	return iCnt;
}
void InsertAtPos(PPNODE head,int no,int pos)
{
	int size=Count(*head);
	if(pos<1 || pos>size+1)
	{
		printf("Invaid size");
		return;
	}
	if(pos==1)
	{
		InsertFirst(head,no);
	}
	else if(pos==(size+1))
	{
		InsertLast(head,no);
	}
	else
	{
		PNODE newn=NULL;
		newn=(PNODE)malloc(sizeof(NODE));
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		PNODE temp=*head;
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

void DeleteFirst(PPNODE head)
{
	if(*head==NULL) //if ll is empty
	{
		printf("invalid position");
		return;
	} 
	
	if((*head)->next==NULL) //single node
	{
		free(*head);
		*head=NULL;
	}
	else     // more than one node
	{
		*head=(*head)->next;
		free((*head)->prev);
		(*head)->prev=NULL;
	}
}
void DeleteLast(PPNODE head)
{
	PNODE temp;
	if(*head==NULL)
	{
		return;
	}
	if((*head)->next==NULL)
	{
		free(*head);
	     *head=NULL;
		 
	}
	else
	{
		temp=*head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}
void DeleteAtPos(PPNODE head,int pos)
{
	PNODE temp=NULL;
	int size=0;
	size=Count(*head);
	if((pos<1) || (pos>size))
	{
		printf("Invalid position");
		return;
	}
	if(pos==1)
	{
		DeleteFirst(head);	
	}	
	else if(pos==size)
	{
		DeleteLast(head);
	}
	else
	{
	
		temp=(*head);
		
		int iCnt=0;
		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		free(temp->next->prev);
		temp->next->prev=temp;
		
	}
		
}


void Display(PNODE head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}

int main()
{
	PNODE first=NULL;
	int iRet=0;
	InsertFirst(&first,30);
	InsertFirst(&first,40);
	InsertFirst(&first,50);
	InsertFirst(&first,60);
	//Display(first);
	//InsertLast(&first,80);
	//printf("after");
	Display(first);
	iRet=Count(first);
	printf("return value is %d \n",iRet);
	//InsertAtPos(&first,90,3);
	DeleteAtPos(&first,1);
	Display(first);
	
    return 0;
}
