#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define INF 9999
#define M 10
int n,i,j,G[M][M],u,k;
void printgrph()
{
	printf("\nThe Graph is displayed in Adjacency Matrix form ::\n");
	for(k=0;k<n;k++)
		printf("   %c",k+65);
	printf("\n");
    for(i=0;i<n;i++)
    {
    	printf("%c",i+65);
        for(j=0;j<n;j++)
            printf("  %d ",G[i][j]);
        printf("\n");
    }
}
void dijkstra(int a)
{
 
    int cost[M][M],distance[M],pred[M];
    int visited[M],count,mindistance,nextnode;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
        {
        	if(G[i][j]==0)
                cost[i][j]=INF;
            else
                cost[i][j]=G[i][j];
		}
	}
    for(i=0;i<n;i++)
    {
        distance[i]=cost[a][i];
        pred[i]=a;
        visited[i]=0;
    }
    
    distance[a]=0;
    visited[a]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INF;
        for(i=0;i<n;i++)
        {
        	if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            } 
		}          
        visited[nextnode]=1;
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
			}
		}
        count++;
    }
    for(i=0;i<n;i++)
    {
    	if(i!=a)
        {
            printf("\n\nMinimum distance of %c to %c = %d",u+65,i+65,distance[i]);
            printf("\nShortest path = %c",i+65);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%c",j+65);
            }while(j!=a);
        }
	}
}
void input()
{
	FILE *fp;
    fp=fopen("graph (2).txt","r");
    if(fp==NULL)
	{
        printf("\nCan't open file...\n");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
            fscanf(fp,"%d",&G[i][j]);
    }
    fclose(fp);
}
int main()
{
    input();
    printgrph();
    char x;
    printf("\nEnter the starting node :: ");
    scanf("%c",&x);
    x=toupper(x);
    u=x-65;
    dijkstra(u);
    printf("\n");
    return 0;
}
