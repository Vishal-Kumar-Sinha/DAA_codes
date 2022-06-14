#include<stdio.h>
#include<stdlib.h>
#define inf 9999
struct node{
    int u;
    int v;
    int wt;
};
struct node gr[10];
int n,graph[10][10];
int k=0;
int bellmanford()
{
    int i,j,wt[10],pred[10];
    for(i=0;i<n;i++)
    {
        wt[i]=999;
        pred[i]=0;
    }
    wt[0]=0;
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<k;j++)
        {
            if(wt[gr[j].u]+gr[j].wt<wt[gr[j].v])
            {
               wt[gr[j].v]= wt[gr[j].u]+gr[j].wt;
               pred[gr[j].v]=gr[j].u;
            }
        }
    }
    for(j=0;j<k;j++)
    {
        if(wt[gr[j].u]+gr[j].wt<wt[gr[j].v])
        return 0;
    }
    printf("\nthe shortst path is:"); 
    for(i=0;i<n;i++)
    {
        printf("\n%c-----%d",i+65,wt[i]);
    }
}
int main()
{
    int i,j;
    FILE *fp;
    fp=fopen("frd.txt","r");
    if(fp==NULL)
    {
        printf("\nError to open file...\n");
		exit(1);
    }
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            fscanf(fp,"%d",&graph[i][j]);
    }
    printf("the graph is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %d ",graph[i][j]);   
        }
    	printf("\n");
	}
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
    	    if(graph[i][j]!=0)

        	{
            	gr[k].u=i;
            	gr[k].v=j;
            	gr[k].wt=graph[i][j];
            	printf("\n%c---%c==%d",gr[k].u+65,gr[k].v+65,gr[k].wt);
            	k++;
        	}
    	}

	}
	bellmanford();
	return 0;
}
