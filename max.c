#include<stdio.h>
int max,min;
int max_min(int arr[],int i,int j)
{
	int max1,min1;
	if(i==j)
	{
		max=arr[i];
		min=arr[i];
	}
	else if(i==j-1)
	{
		if(arr[i]>arr[j])
		{
			max=arr[i];
			min=arr[j];
		}
		else
		{
			max=arr[j];
			min=arr[i];
		}
	}
	else
	{
		int mid=(i+j)/2;
		max_min(arr,i,mid);
		max1=max,min1=min;
		max_min(arr,mid+1,j);
		if(max<max1)
			max=max1;
		if(min>min1)
			min=min1;
	}
}
int main()
{
	int i,n,l,r;
	printf("\nEnter array size :: ");
	scanf("%d",&n);
	int arr[n];printf("\nEnter array elements");
	for(i=0;i<=n-1;i++)
		scanf("%d",&arr[i]);
	l=0;
	r=n-1;
	max_min(arr,l,r);
	printf("\nMaximum element= %d\nMinimum element= %d\n",max,min);
	return 0;
}
