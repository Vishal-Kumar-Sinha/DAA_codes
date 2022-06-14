#include<stdio.h>
#include<stdlib.h>
#define max 100

int g[max][max], queue[max],visited[max],tr[max];
int f=-1,r=-1,k=0,n;
int isEmpty() 
{
    if(f==-1 || f>r)
        return 1;
    else
        return 0;
}
void bf_trav()
{
    int i,u=0,w;
    for(i=0;i<n;i++)
        visited[i]=0;
    if(f==-1 && r==-1)
	{
        ++f;
        queue[++r]=u;
    }
    visited[u]=1;
    tr[k++]=queue[r];
    while(!(isEmpty()))
	{
        u=queue[f++];
        for(i=0;i<n;i++)
		{
			if(g[u][i]==1 && visited[i]==0)
			{
                queue[++r]=i;
                tr[k++]=queue[r];
                visited[i]=1;
            }
        }
    }
}
void print()
{
    int i;
    printf("\n\n\nBreadth First Search is :: ");
    for(i=0;i<k;i++)
        printf("%4c",tr[i]+65);
    printf("\n");
}
void printgrph(int n)
{
	int i,j,k;
	printf("\nThe Graph is displayed in Adjacency Matrix form ::\n");
	for(k=0;k<n;k++)
		printf("   %c",k+'A');
	printf("\n");
    for(i=0;i<n;i++)
    {
    	printf("%c",i+'A');
        for(j=0;j<n;j++)
            printf("  %d ",g[i][j]);
        printf("\n");
    }
}
int main()
{
    FILE *fp;
    int i,j;
    fp=fopen("graph.txt","r");
    if(fp == NULL)
	{
        printf("\nCan't open file...\n");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
            fscanf(fp,"%d",&g[i][j]);
    }
    fclose(fp);
    printgrph(n);
    bf_trav();
    print();
    return 0;
}
