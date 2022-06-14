#include<stdio.h>
#include<stdlib.h>
#define inf 9999
int p[10][10],n,i,j,k,w,e,u,v;
int min(int a,int b)
{
	if(a<b)
		return a;
    else
		return b;
}
void floyds()
{
    for(k=1;k<=n;k++)
    {
    	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=n;j++)
    		{
    			if(i==j)
        			p[i][j]=0;
    			else
        			p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
		}
	}
}
void main()
{
    FILE*fp;
	fp=fopen("warsh.txt","r");
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&e);
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    		fscanf(fp,"%d",&p[i][j]);
	}
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
    	{
			if(p[i][j]==0)
				p[i][j]=inf;
		}
    }
    floyds(p,n);
    printf("\n Transitive closure:\n");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    		printf("%d \t",p[i][j]);
        printf("\n");
    }
    printf("\n The shortest paths are ::\n PATH\tCOST");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
		{
			if(i!=j)
    			printf("\n %c-%c  %4d",i+64,j+64,p[i][j]);
		}
	}
	printf("\n");
}
