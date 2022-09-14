#include<stdio.h>
#include<stdlib.h>

//  algorithm 
//  step 1 first design struct node
//  step 2 typedef which use to use name for existing struct data


struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;  //typedef which is use to another name of existing variable 
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head,int no) //PPNODE which is accept ptr send by main function
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	if(!newn)
		printf("error \n");
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		newn->next=*head;
		*head=newn;
	}
}

void InsertLast(PPNODE head,int no)
{
	//first allocate memory for next pointer
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL) //check whether first node contain another node or not
	{
		*head=newn; //if node is empty then newn is the first node of that linked list 
	}
	else
	{
		PNODE temp=NULL;
		temp=(*head);
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
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
	if((pos<1) || pos>(size+1))
	{
		printf("Invalid position");
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
		
		PNODE temp=NULL;
		temp=*head;
	     int iCnt=0;
		for(iCnt=1;iCnt<pos-1;iCnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		
	}
}

void DeleteFirst(PPNODE head)
{
	if((*head)==NULL)
	{
		return;
	}
    else
	{
		PNODE temp=NULL;
		temp=*head;
		*head=temp->next;
		free(temp);
	}
	
}
void DeleteLast(PPNODE head)
{
	if(*head==NULL)
	{
		return;
	}
	else
	{
		PNODE temp=NULL;
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
	int size=Count(*head);
	int iCnt=0;
	if(pos<0 || pos>size)
	{
		printf("Invaid Position");
		return;
	}
	if(pos==1)
	{
		DeleteFirst(head);
		
	}
	else if(pos==(size))
	{
		DeleteLast(head);
	}
	else
	{
		PNODE temp=*head;
		for(iCnt=1;iCnt<pos-1;iCnt++)
		{
			temp=temp->next;
		}
		PNODE tempdelete=NULL;
		tempdelete=temp->next;
		temp->next=temp->next->next;
		free(tempdelete);
	    
	}
	
}

void Display(PNODE head)
{
	while(head!=NULL)
	{
		printf("%d \n",head->data);
		head=head->next;
	}
}

int main()
{
 	PNODE first=NULL;
	InsertFirst(&first,5);  //&first which pass the addres of first of struct node ptr
	InsertFirst(&first,7);
	InsertFirst(&first,8);
    InsertFirst(&first,9);
	InsertFirst(&first,10);
    int iRet=0;
	printf("after \n");
	Display(first);  //only pass value not a address
	//printf("before \n");
	//InsertLast(&first,45); //insert at the end of the last 
    //Display(first);
	//InsertAtPos(&first,46,3);
	iRet=Count(first);
	printf("Number of node is :%d\n",iRet);
	//Display(first);
	
	//DeleteLast(&first);
	DeleteAtPos(&first,2); 
	Display(first);
	return 0;
}