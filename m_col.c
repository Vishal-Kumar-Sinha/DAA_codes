#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 15
int n,m,g[max][max],color[max],cnt=0;
void nextvalue(int k)
{
    int j;
    while(1){
        color[k]=(color[k]+1)%(m+1);
        if(color[k]==0)
        {
            return;
        }
        for(j=1;j<k;j++)
        {
            if(g[k][j]==1 && color[j]==color[k])
            break;
        }
        if(j==k)
        {
            return;
        }
    }
}
void mcolour(int k)
{
    while(1)
    { 
        int i,j;
        nextvalue(k);
        if(color[k]==0)
            return;
        if(k==n)
        {
    		printf("\nSolution %d is :: ",++cnt);
            for(i=1;i<=n;i++)
                printf("%4c = %d",i+64,color[i]);
            printf("\n");
        }
        else
            mcolour(k+1);
    }
}
void main()
{
    int i,j;
    FILE *fp;
    fp=fopen("color.txt","r");
    if(fp==NULL)
	{
        printf("\nFile not found...");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(i=1;i<=n;i++)
	{
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&g[i][j]);
    }
    for(i=0;i<n;i++)
        color[i]=0;
    printf("\nEnter number of colors :: ");
    scanf("%d",&m);
    mcolour(1);
    if(cnt==0)
    {
    	printf("\nColoring not possible...\n");
    	return;
	}   
}
