#include<stdio.h>
#include<stdlib.h>
#define max 100
int a[max];
void heap_adjust(int i,int n)
{
	int j,key;
	j=2*i;
	key=a[i];
	while(j<=n)
	{
		if(j<n && a[j]<a[j+1])
			j++;
		if(key>=a[j])
			break;
		a[j/2]=a[j];
		j=j*2;
	}
	a[j/2]=key;
}
void make_heap(int n)
{
	int i;
	for(i=n/2;i>=1;i--)
		heap_adjust(i,n);
}
void heap_sort(int n)
{
	int i,temp;
	make_heap(n);
	for(i=n;i>=2;i--)
	{
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		heap_adjust(1,i-1);
	}
}
int main()
{
	int i,n;
	printf("\nEnter array size :: ");
	scanf("%d",&n);
	printf("\nEnter array elements :: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	heap_sort(n);
	printf("\nThe sorted array is :: ");
	for(i=1;i<=n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
	return 0;
}
