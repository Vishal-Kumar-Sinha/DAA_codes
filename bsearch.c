#include<stdio.h>
int binsearch(int a[],int x,int low,int high)
{
    int mid=(low+high)/2;
    if(low>high)
    	return -1;
    if(x==a[mid])
    	return(mid);
    else if(x<a[mid])
    	binsearch(a,x,low,mid-1);
    else
		binsearch(a,x,mid+1,high);
}
int main()
{
    int num,i,key,position,low,high,list[25];
    printf("\nEnter the total number of elements: ");
    scanf("%d",&num);
    printf("\nEnter the elements of list: ");
    for(i=0;i<num;i++)
    	scanf("%d",&list[i]);
    low=0;
    high=num-1;
    printf("\nEnter element to be searched: ");
    scanf("%d",&key);
    position=binsearch(list,key,low,high);
    if(position!=-1)
    	printf("\nThe number %d is present at %d",key,(position+1));
    else
    	printf("\nThe number %d is not present in the list",key);
    return 0;
}
