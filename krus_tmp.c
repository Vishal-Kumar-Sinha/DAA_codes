#include<stdio.h>
#include<stdlib.h>
#define MAX 30
typedef struct edge
{
	int u,v,w;
}edge;

typedef struct edgelist
{
	edge data[MAX];
	int n;
}edgelist;

edgelist elist;
int G[MAX][MAX],n;
edgelist spanlist;

int find(int belongs[],int vertexno)
{
	return(belongs[vertexno]);
}
void union1(int belongs[],int c1,int c2)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(belongs[i]==c2)
			belongs[i]=c1;
	}
}
void sort()
{
	int i,j;
	edge temp;
	for(i=0;i<elist.n;i++)
	{
		for(j=0;j<elist.n-1;j++)
		{
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
			}
		}
	}
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
            printf("  %d ",G[i][j]);
        printf("\n");
    }
}
void kruskal()
{
	int belongs[MAX],i,j,cno1,cno2;
	elist.n=0;
 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i+1;j++)
		{
			if(G[i][j]!=0)
			{
				elist.data[elist.n].u=i;
				elist.data[elist.n].v=j;
				elist.data[elist.n].w=G[i][j];
				elist.n++;
			}
		}
	}
	sort();
	for(i=0;i<n;i++)
	{
		belongs[i]=i;
		spanlist.n=0;
	}
	for(i=0;i<elist.n;i++)
	{
		cno1=find(belongs,elist.data[i].u);
		cno2=find(belongs,elist.data[i].v);
		if(cno1!=cno2)
		{
			spanlist.data[spanlist.n]=elist.data[i];
			spanlist.n=spanlist.n+1;
			union1(belongs,cno1,cno2);
		}
	}
}
void print()
{
	int i,cost=0;
	printf("\nEdges\tCost");
	for(i=0;i<spanlist.n;i++)
	{
		printf("\n%c-%c\t%d",spanlist.data[i].u+64,spanlist.data[i].v+64,spanlist.data[i].w);
		cost=cost+spanlist.data[i].w;
	}
	printf("\n\nCost of the spanning tree = %d.\n",cost);
}
void main()
{
	int i,j,total_cost;
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
            fscanf(fp,"%d",&G[i][j]);
    }
    fclose(fp);
    printgrph(n);
	kruskal();
	print();
}
