#include<stdio.h>
void swap(int arr[],int a,int b)
{
	int t=arr[a];
	arr[a]=arr[b];
	arr[b]=t;
}
int partition(int arr[],int low,int high)
{
	int i=low-1;
	int j=high;
	int pivot=arr[high];
	while(i<j)
	{
		do{
			i++;
		}while(arr[i]<pivot);
		do{
			j--;
		}while(j>=0 && arr[j]>pivot);
		if(i<j)
			swap(arr,i,j);
	}
	swap(arr,i,high);
	return i;
}
int qsort(int a[],int p,int r)    
{
    if(p<r)
    {
        int q;
        q=partition(a,p,r);
        qsort(a,p,q-1);
        qsort(a,q+1,r);
    }
}
void printArray(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%4d",a[i]);
    printf("\n");
}
int main()
{
	int n,i;
	printf("\nEnter array size :: ");
	scanf("%d",&n);
	if(n<=0)
		printf("\nInvalid input...!\n");
	else if(n>0)
    {
		int arr[n];
		printf("\nEnter array elements :: ");
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		if(n==1)
		printf("\nThe array is already sorted..!\n");
		else if(n==2)
			{
				if(arr[0]>arr[1])
					swap(arr,0,1);
				printf("\nThe sorted array is :: %d\t%d\n",arr[0],arr[1]);
			}
		else
		{
			qsort(arr,0,n-1);
			printArray(arr,n);
		}
	}
	return 0;
}
