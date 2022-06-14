#include<stdio.h>
#include<stdlib.h>
#define s 100
typedef struct item{
	//char id;
	float p;
	float w;
}item;
int m,n;
float x[s],tp=0;
item a[s];
item temp;
void input()
{
	int i;
	printf("\nEnter number of items :: ");
	scanf("%d",&n);
	printf("\nEnter the profits :: ");
	for(i=0;i<n;i++)
		scanf("%f",&a[i].p);
	printf("\nEnter the corresponding weights :: ");
	for(i=0;i<n;i++)
		scanf("%f",&a[i].w);
	printf("\nEnter capacity :: ");
	scanf("%d",&m);
}
void sort()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((a[j].p/a[j].w)<(a[j+1].p/a[j+1].w))
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void print(int c)
{
	int i;
	printf("\n-------------------------------------------\n");
	printf("%10s%10s%10s\n","Items","Profit","Weight");
  	for(i=0;i<n;i++)
    	printf("%10c\t%.1f\t%.1f\n",i+65,a[i].p,a[i].w);
    printf("\n-------------------------------------------\n");
	printf("\nx[i] values :: ");
	for(i=0;i<c;i++)
		printf("\t%0.2f",x[i]);
	printf("\n\nTotal profit is :: %0.2f",tp);
}
void knapsack()
{
	int i,u=m,c=0;
	for(i=0;i<n;i++)
		x[i]=0;
	for(i=0;i<n;i++)
	{
		if(u>a[i].w)
		{
			x[i]=1.0;
			tp=tp+(x[i]*a[i].p);
			u=u-a[i].w;
			c++;
		}
		else
			break;
	}
	if(i<=n)
	{
		x[i]=u/a[i].w;
		tp=tp+(x[i]*a[i].p);
		c++;
	}
	print(c);
}
int main()
{
	input();
	sort();
	knapsack();
	return 0;
}
