#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head,PPNODE tail,int no)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	
	if((*head==NULL)&&(*tail==NULL))
	{
		*head=newn;
		*tail=newn;
	}
	else
	{
		newn->next=(*head);
		*head=newn;
	}
	(*tail)->next=(*head);
}

void InsertLast(PPNODE head,PPNODE tail,int no)
{
	
    PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	
	if((*head==NULL)&&(*tail==NULL))
	{
		*head=newn;
		*tail=newn;
	}
	else
	{
		(*tail)->next=newn;
		*tail=newn;
	}
	(*tail)->next=*head;
}

int Count(PNODE head,PNODE tail)
{
	int iCnt=0;
	PNODE temp=head;
	
	if((head==NULL)&&(tail==NULL))
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

void InsertAtPos(PPNODE head,PPNODE tail,int no,int pos)
{
	int size=Count(*head,*tail);
	if((pos<1)||(pos>size+1))
	{
		printf("Invalid position");
		return;
	}
	if(pos==1)
	{
		InsertFirst(head,tail,no);
	}
	else if(pos==size+1)
	{
		InsertLast(head,tail,no);
	}
	else
	{
		PNODE newn=NULL;
		
		newn=(PNODE)malloc(sizeof(NODE));
		
		newn->data=no;
		newn->next=NULL;
		
		PNODE temp=NULL;
		temp=(*head);
		int iCnt=0;
		for(iCnt=1;iCnt<pos-1;iCnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}

void DeleteFirst(PPNODE head,PPNODE tail)
{
	if((*head==NULL) && (*tail==NULL))
	{
		return;
	}
	else if((*head)==(*tail))
	{
		free (*head);
		*head=NULL;
		*tail=NULL;
		
		(*tail)->next=(*head);
	}
	else
	{
		*head=(*head)->next;
		free ((*tail)->next);
		(*tail)->next=*head;
	}
}

void DeleteLast(PPNODE head,PPNODE tail)
{
	if((*head==NULL) && (*tail==NULL))
	{
		return;
	}
	else if(*head==*tail)
	{
		free (*tail);
		*head=NULL;
		*tail=NULL;
		
	}
	else
	{
		PNODE temp=(*head);
		while(temp->next !=(*tail))
		{
			temp=temp->next;
		}
		
		free (*tail);
		(*tail)=temp;
		
		(*tail)->next=*head;
	}
}

void DeleteAtPos(PPNODE head,PPNODE tail,int pos)
{
	int size=Count(*head,*tail);
	
	if((pos<1)&&(pos>size))
	{
		printf("invalid position \n");
		return;
	}
	if(pos==1)
	{
		DeleteFirst(head,tail);
	}
	else if(pos==size)
	{
		DeleteLast(head,tail);
	}
	else
	{
		PNODE temp1=(*head);
		int iCnt=0;
		
		for(iCnt=1;iCnt<pos-1;iCnt++)
		{
			temp1=temp1->next;
		}
		PNODE temp2=temp1->next;
		temp1->next=temp2->next;
		free (temp2);	
	}
}


void Display(PNODE head,PNODE tail)
{
	PNODE temp=head;
	
	if((head==NULL)&&(tail==NULL))
	{
		return;
	}
	do
	{
		printf("%d \n",temp->data);
		temp=temp->next;
		
	}while(temp!=head);
	printf("\n");

}



int main()
{
	PNODE first=NULL;
	PNODE last=NULL;
	InsertFirst(&first,&last,4);
	InsertFirst(&first,&last,5);
	InsertFirst(&first,&last,6);
	InsertLast(&first,&last,100);
	InsertAtPos(&first,&last,300,5);
	int ret=Count(first,last);
	Display(first,last);
	DeleteFirst(&first,&last);
	DeleteLast(&first,&last);
	DeleteAtPos(&first,&last,2);
	printf("before \n");
	Display(first,last);
	return 0;
}
