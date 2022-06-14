#include<stdio.h>
int arr[100];
void merge(int left, int mid, int right)
{
    int i,j,k;
    int b[right];
    i=left,j=mid+1,k=left;
    while(i<=mid && j<=right)
    {
    	if(arr[i]<arr[j])
    	{
    		b[k]=arr[i];
    		i++;
		}
		else
		{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=arr[i];
		i++;
		k++;
	}
	while(j<=right)
	{
		b[k]=arr[j];
		j++;
		k++;
	}
	for(i=left;i<=right;i++)
		arr[i]=b[i];
}
void mergeSort(int left, int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);
        merge(left,mid,right);
    }
}

int main()
{
    int n,i;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	puts("\nEnter array elements");
	for(i=0;i<=n-1;i++)
	    scanf("%d",&arr[i]);
	puts("\nBefore sorting...");
	for(i=0;i<=n-1;i++)
	    printf("%d ",arr[i]);
    mergeSort(0,n-1);
    puts("\nAfter sorting (Ascending Order)...");
	for(i=0;i<=n-1;i++)
	    printf("%d ",arr[i]);
	puts("\nAfter sorting (Descending Order)...");
	for(i=n-1;i>=0;i--)
	    printf("%d ",arr[i]); 
    return 0;
}
