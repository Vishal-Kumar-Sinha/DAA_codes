#include<stdio.h>
#include<stdlib.h>
#define INF 9999
#define MAX 20
int G[MAX][MAX],spanning[MAX][MAX],i,j,n;
void input()
{
	FILE *fp;
    fp=fopen("graph (2).txt","r");
    if(fp==NULL)
	{
        printf("\nCan't open file...");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
		{
            fscanf(fp,"%d",&G[i][j]);
        }
    }
    fclose(fp);
}
int prims()
{
	int cost[MAX][MAX];
	int u,v,min_distance,distance[MAX],from[MAX];
	int visited[MAX],no_of_edges,min_cost;
	//create cost[][] matrix,spanning[][]
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=INF;
			else
				cost[i][j]=G[i][j];
				spanning[i][j]=0;
		}
	}
	//initialise visited[],distance[] and from[]
	distance[0]=0;
	visited[0]=1;
	for(i=1;i<n;i++)
	{
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	min_cost=0; //cost of spanning tree
	no_of_edges=n-1; //no. of edges to be added
	while(no_of_edges>0)
	{
	//find the vertex at minimum distance from the tree
		min_distance=INF;
		for(i=1;i<n;i++)
		{
			if(visited[i]==0&&distance[i]<min_distance)
			{
				v=i;
				min_distance=distance[i];
			}
		}
		u=from[v];
		//insert the edge in spanning tree
		spanning[u][v]=distance[v];
		spanning[v][u]=distance[v];
		no_of_edges--;
		visited[v]=1;
		//updated the distance[] array
		for(i=1;i<n;i++)
		{
			if(visited[i]==0&&cost[i][v]<distance[i])
			{
				distance[i]=cost[i][v];
				from[i]=v;
			}
		}
		min_cost=min_cost+cost[u][v];
	}
	return(min_cost);
}
void printgrph(int n,int a[MAX][MAX])
{
	int k;
	for(k=0;k<n;k++)
		printf("   %c",k+65);
	printf("\n");
    for(i=0;i<n;i++)
    {
    	printf("%c",i+65);
        for(j=0;j<n;j++)
            printf("  %d ",a[i][j]);
        printf("\n");
    }
}
int main()
{
	int total_cost;
	input();
	printf("\nThe Graph is displayed in Adjacency Matrix form ::\n");
    printgrph(n,G);
	total_cost=prims();
	printf("\nThe spanning tree is in Adjacency Matrix form ::\n");
	printgrph(n,spanning);
	printf("\n\nTotal cost of spanning tree = %d\n\n",total_cost);
	return 0;
}
