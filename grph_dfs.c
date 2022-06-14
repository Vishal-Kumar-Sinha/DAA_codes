#include<stdio.h>
#include<stdlib.h>
#define max 100

int g[max][max],visited[max];
int n;
void df_trav(int v)
{
	int i;
	visited[v]=1;
	printf("%4c",65+v);
	for(i=n-1;i>=0;i--)
	{
		if(g[v][i] && !visited[i])
			df_trav(i);
	}
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
    printf("\n\n\nDepth First Search is :: ");
    df_trav(0);
    return 0;
}
