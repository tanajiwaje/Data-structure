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
//////////////Bubble sort/////////////////////////
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(Arr[j]>Arr[j+1])
			{
				temp=Arr[j+1];
				Arr[j+1]=Arr[j];
				Arr[j]=temp;
			}
		}
	}
/////////////////////////////////////////////////////	
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