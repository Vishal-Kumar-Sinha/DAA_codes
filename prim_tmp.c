#include<stdio.h>
#include<stdlib.h>
#define INF 999999
int a,b,u,v,n,i,j,ne=1;
int visited[10]= {0},min,mincost=0,cost[10][10];
void input()
{
	int i,j;
	FILE *fp;
    fp=fopen("graph (2).txt","r");
    if(fp==NULL)
	{
        printf("\nCan't open file...");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(i=1;i<=n;i++)
	{
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&cost[i][j]);
    }
    fclose(fp);
}
void printgrph(int n)
{
	int i,j,k;
	printf("\nThe Graph is displayed in Adjacency Matrix form ::\n");
	for(k=1;k<=n;k++)
		printf("   %c",k+64);
	printf("\n");
    for(i=1;i<=n;i++)
    {
    	printf("%c",i+64);
        for(j=1;j<=n;j++)
            printf("  %d ",cost[i][j]);
        printf("\n");
    }
}
void prim()
{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[i][j]==0)
		    	cost[i][j]=INF;
		}
	}
	visited[1]=1;
	printf("\n");
	printf("\nThe edges of Minimum Spanning Tree with costs are ::\n");
    printf("%4s\t%s","Edge","Cost");
	while(ne<n)
	{
		for(i=1,min=INF;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
		    	{
		    		if(visited[i]!=0)
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
				}
			}	
		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n(%c-%c)\t%d",a+64,b+64,min);
			ne++;
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=INF;
	}
	printf("\n\n\nMinimun cost = %d\n",mincost);
}
int main()
{
	input();
	printgrph(n);
	prim();
	return 0;
}
