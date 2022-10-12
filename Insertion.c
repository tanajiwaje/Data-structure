#include<stdio.h>


void Accept(int size)
{
	int Arr[size];
	int temp=0;
	
	for(int i=0;i<size;i++)
	{
         scanf("%d",&Arr[i]);
	}
	
	for(int i=0;i<size;i++)
	{
         printf("%d",Arr[i]);
	}
	
//////////////////////////////////////////////////	
////////////// InsertionSort /////////////////////
	int i=0,j=0,selected=0;
	for(i=1;i<size;i++)
	{
		for(j=i-1,selected=Arr[i];(j>=0) && (Arr[j]>selected);j--)
		{
			Arr[j+1]=Arr[j];
		}
		Arr[j+1]=selected;
	}
	
//////////////////////////////////////////////////
	printf("after swapping");
	for(int i=0;i<size;i++)
	{
         printf("%d",Arr[i]);
	}
}

int main()
{
	int size=0;
	printf("Enter size of array");
	scanf("%d",&size);
	
	Accept(size);

	return 0;
}