//try to solved algorithem
#include<stdio.h>
#include<stdlib.h>

void Accept(int size)
{
	int arr[size];
	int i=0;
	int temp=0;
	int j=0;
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
   
   printf("after sorting");
   
   for(i=0;i<size;i++)
   {
	   for(j=0;j<size;j++)
	   {
		   if(arr[i]<arr[j])
		   {
			   temp=arr[j];
			   arr[j]=arr[i];
			   arr[i]=temp;
		   }
		   
	   }
   }
   
   printf("after sorting algorithm");
   for(i=0;i<size;i++)
   {
	   printf("%d\n",arr[i]);
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