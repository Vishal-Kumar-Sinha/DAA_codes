#include <stdio.h>
#include<limits.h>
#define INFY 9999
long int m[20][20];
int s[20][20];
int p[20],i,j,len,k,n,cost=0;
void print_optimal(int i,int j)
{
	if(i == j)
		printf(" A%d ",i);
	else
    {
      	printf("( ");
      	print_optimal(i,s[i][j]);
      	print_optimal(s[i][j]+1,j);
      	printf(" )");
   	}
}
void matrixorder()
{
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(len=2;len<=n;len++)
	{
		for(i=1;i<=n-len+1;i++)
		{
			j=i+len-1;
			m[i][j]=INFY;
			for(k=i;k<=j-1;k++)
			{
				cost=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(cost<m[i][j])
				{
					m[i][j]=cost;
					s[i][j]=k;
				}
			}
			
		}
	}
	
}
int main()
{
	int k;
	FILE*fp;
	fp=fopen("mat.txt","r");
	fscanf(fp,"%d",&n);
	for(k=0;k<n;k++)
	{
 		fscanf(fp,"%d",&p[k]);
	}
	matrixorder();
	print_optimal(1,4);
	printf("\n");
	return 0;
}
