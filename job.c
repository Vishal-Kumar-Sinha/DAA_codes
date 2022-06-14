#include<stdio.h>
#include<stdlib.h>
#define m 100
#define min(a,b) (a<b?a:b)

typedef struct a{
	char id;
	int d;
	int p;
}job;
job temp;
job a[m];
int n,slot[m],mp=0,t=0,dm=0;
void input()
{
	int i;
	printf("\nEnter number of jobs :: ");
	scanf("%d",&n);
	//printf("\nEnter the %d job ids :: ",n);
	for(i=0;i<n;i++)
		a[i].id=i+65;
		//scanf("%c",&a[i].id);
	printf("\nEnter the profits :: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i].p);
	printf("\nEnter the corresponding deadlines :: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i].d);
}
void sort()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((a[j].p)<(a[j+1].p))
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void jsd()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
    	if(a[i].d>dm)
      	    dm=a[i].d;
    }//[-1 denotes EMPTY]
    for(i=1;i<=dm;i++)
        slot[i]=-1;
    for(i=1;i<=n;i++)
	{
        k=min(dm,a[i-1].d);//a[] starts with index 0 but slot[] starts with index 1
        while(k>=1)
		{
            if(slot[k]==-1)
			{
        		slot[k]=i-1;
        		t++;
        		break;
        	}
        	k--;
    	}
    	if(t == dm)
        	break;
    }
}
void print()
{
	int i;
	printf("\n----------------------------------------\n");
	printf("%10s  %10s  %10s\n","Job","Deadline","Profit");
  	for(i=0;i<n;i++)
    	printf("%10c  %10i  %10i\n",a[i].id,a[i].d,a[i].p);
	printf("\n----------------------------------------\n");
	printf("\nMaximum deadline is :: %d.",dm);
	printf("\nRequired job sequence is :: ");
    for(i=1;i<=dm;i++)
	{
    	printf("%c",a[slot[i]].id);
    	if(i<dm)
        	printf(" --> ");
    }
    for(i=1;i<=dm;i++)
    	mp+=a[slot[i]].p;
    printf("\nMax Profit is :: %d.\n\n",mp);
}
int main()
{
	input();
	sort();
	jsd();
	print();
	return 0;
}
