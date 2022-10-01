#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head,int no)
{
	PNODE newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	
	if(*head != NULL)
	{
		newn->next=*head;
	}
	*head=newn;		
}

void Display(PNODE head)
{
	printf("Elements of linked list are \n");
	while(head!=NULL)
	{
		printf("|%d|->",head->data);
		head=head->next;
	}
	printf("NULL \n");
}

void EvenDisplay(PNODE head)
{
	int pos=1;
	while(head!=NULL)
	{
		if((head->data%2)==0)
		{
			printf("Position %d data : %d \n",pos,head->data);
		}
		head=head->next;
		pos++;
	}
}

void DeleteEven(PPNODE head)
{
	PNODE first=NULL;
	PNODE second=NULL;
	PNODE temp=NULL;
	
	if(*head==NULL)
	{
		return;
	}
	
	if((*head)->next==NULL)
	{
		if((((*head)->data)%2)==0)
		{
			free(*head);
			*head=NULL;
			return;
		}
		else
		{
			return;
		}
	}
	first=*head;
	second=(*head)->next;
	
	while(second!=NULL)
	{
		if((second->data)%2==0)
		{
			temp=second;
			first->next=second->next;
			free(temp);
			second=first->next;
		}
		else
		{
			first=second;
			second=first->next;
		}
	}
	
	if(((*head)->data)%2==0)
	{
		temp=*head;
		(*head)=(*head)->next;
		free(temp);
	}
	
}

int main()
{
	PNODE first=NULL;
	int ret=0;
	InsertFirst(&first,50);
	InsertFirst(&first,60);
	InsertFirst(&first,70);
	Display(first);
	DeleteEven(&first);
	Display(first);
	
	return 0;
}





