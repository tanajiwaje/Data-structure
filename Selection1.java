import java.lang.*;
import java.util.*;

class now
{
	public int arr[];
	public int i,j;
	public int select;
    public int temp;
	now(int no)
	{
		arr=new int[no];
		i=0;
		j=0;
		select=0;
		temp=0;
	}
	
	public void Accept()
	{
		Scanner sobj=new Scanner(System.in);
	    System.out.println("Enter Elements of an array");
        for(i=0;i<arr.length;i++)
		{
			arr[i]=sobj.nextInt();
		}			
	}
	
	public void Display()
	{
		for(i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]);
		}
		
	}
	
	public void Selection()
	{
		for(i=0;i<arr.length;i++)
		{
			select=i;
			for(j=i+1;j<arr.length;j++)
			{
				if(arr[select]>=arr[j])
				{
					select=j;
				}
			}
			if(i!=select)
			{
				temp=arr[i];
				arr[i]=arr[select];
				arr[select]=temp;
			}
		}
	}

}

class Selection1
{
	public static void main(String arg[])
	{
		Scanner sobj=new Scanner(System.in);
		
		System.out.println("Enter how many number you want to store");
		int no=sobj.nextInt();
		
		now obj=new now(no);
		obj.Accept();
	    
		System.out.println("this is elements");
		obj.Display();
		
		obj.Selection();
		System.out.println("after sorting");
		obj.Display();
		
	}
	
}