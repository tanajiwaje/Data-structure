#include<stdio.h>
#include<stdlib.h>

static int cnt;
struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void push(PPNODE head,int no)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	
	newn->next=(*head);
	*head=newn;
	cnt++;
}

void pop(PPNODE head)
{
	int no=(*head)->data;
	
	PNODE temp=(*head);
	(*head)=(*head)->next;
	free(temp);
	cnt--;
}

int Count()
{
	return cnt;
}
void Display(PNODE head)
{
	while(head!=NULL)
	{
		printf("%d  ",head->data);
		head=head->next;
	}
}

int main()
{
	PNODE first=NULL;
	int ret=0;
	push(&first,4);
	push(&first,31);
	push(&first,42);
	push(&first,33);
	push(&first,64);
	Display(first);
	pop(&first);
	Display(first);
	ret=Count();
	printf("elements is :%d",ret);
}