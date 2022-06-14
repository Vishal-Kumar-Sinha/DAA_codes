#include<stdio.h>
#include<stdlib.h>
#define p 100
int i,W,n,wt[p],pft[p],knap[p][p];
int max(int a,int b)
{
   if(a>b)
      return a;
   else
      return b;
}
void input()
{
	FILE*fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL)
	{
		printf("\nCan't open file...\n");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&W);
	for(i=0;i<n;i++)
		fscanf(fp,"%d",&pft[i]);
	for(i=0;i<n;i++)
		fscanf(fp,"%d",&wt[i]);
	fclose(fp);
}
int knapsack()
{
   	int i,w;
   	for(i=0;i<=n;i++)
	{
      	for(w=0;w<=W;w++)
		{
        	if(i==0||w==0)
            	knap[i][w]=0;
         	else if(wt[i-1]<=w)
            	knap[i][w]=max(pft[i-1]+knap[i-1][w-wt[i-1]],knap[i-1][w]);
         	else
            	knap[i][w]=knap[i-1][w];
      }
   }
   return knap[n][W];
}
int main()
{
	int i,w;
	input();
	printf("\n\nThe solution is :: %d\n\n",knapsack());
	printf("\nThe visualization table is ::\n");
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
			printf("%4d",knap[i][w]);
		printf("\n");
	}
	return 0;
}













/*#include<stdio.h>
#include<stdlib.h>
#define m 100
#define max(a,b) (a>b?a:b)
int i,j,k,n,w,wt[m],p[m],x[m][m],tp;
void input()
{
	FILE*fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL)
	{
		printf("\nCan't open file...\n");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&w);
	for(i=0;i<n;i++)
		fscanf(fp,"%d",&p[i]);
	for(i=0;i<n;i++)
		fscanf(fp,"%d",&wt[i]);
	fclose(fp);
}
int knapsack()
{
	for(i=0;i<=n;i++)
		x[i][0]=0;
	for(j=0;j<=w;j++)
		x[0][j]=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(wt[i]<=j)
				x[i][w]=max((p[i]+x[i-1][j-wt[i]]),x[i-1][j]);
			else
				x[i][j]=x[i-1][j];
		}
	}
	return x[n][w];
}
void print()
{
	tp=x[n][w];
	j=w;
	printf("\nThe selected items are :: ");
	for(i=n;i>0;i--)
	{
		if(tp==x[i-1][j])
			continue;
		else
		{
			printf("%d",i);
			j=j-wt[i];
			tp=tp-p[i];
			if(tp==0)
				break;
		}
	}
}
int main()
{
	input();
	printf("%d",knapsack());
	print();
	printf("\n");
	return 0;
}*/
