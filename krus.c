#include<stdio.h>
#include<stdlib.h>
#define VAL 999
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int i)
{
    while(parent[i])
    i=parent[i];
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
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
void krus()
{
	for(i=1;i<=n;i++)
	{
        for(j=1;j<=n;j++)
		{
            if(cost[i][j]==0)
                cost[i][j]=VAL;
        }
    }
    printf("\nThe edges of Minimum Spanning Tree with weights are ::\n");
    printf("%4s%10s\n","Edge","weight");
    while(ne<n)
    {
        for(i=1,min=VAL;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("%c-%c%8d\n",a+64,b+64,min);
            mincost=mincost+min;
            ne++;
        }
        cost[a][b]=cost[b][a]=VAL;
    }
    printf("\nWeight of the minimum spanning tree = %d\n",mincost);
}
int main()
{
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
		{
            fscanf(fp,"%d",&cost[i][j]);
        }
    }
    printgrph(n);
    krus();
    fclose(fp);
    return 0;
}
