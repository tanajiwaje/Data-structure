#include<stdio.h>
#include<stdlib.h>

///static int Count;

static int Countno;
struct node 
{
	int data;
    struct node *next;
	
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Inqueue(PPNODE head,int *cnt,int no)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		PNODE temp=(*head);
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;	
	}
	cnt++;
	Countno++;
}

void Dequeue(PPNODE head,int *cnt)
{
	int no;
	if(cnt==0)
	{
		printf("Queue is empty");
		return;
	}
	no=(*head)->data;
	PNODE temp=(*head);
	(*head)=(*head)->next;
	free (temp);
	cnt--;
	Countno--;
	//printf("%d",no);
}


void Display(PNODE head)
{
    while(head!=NULL)
	{
		printf("%d  ",head->data);
		head=head->next;
	}
}

int CountNode(PNODE head)
{
	
}

int main()
{
	PNODE first=NULL;
	int Count=0;
	int ret=0;
	Inqueue(&first,&Count,5);
	Inqueue(&first,&Count,7);
	Inqueue(&first,&Count,4);
	//Inqueue(&first,2);
	Display(first);
	printf("........");
	//Dequeue(&first,&Count);
	//Dequeue(&first,&Count);
	Display(first);
	ret=CountNode(first);
	printf("count is :%d",Countno);
	return 0;
}