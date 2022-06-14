#include<stdio.h>
#include<stdlib.h>
#define max 100

struct graph {
    int data;
    struct graph *next;
}*head[max], *p;

int visited[max],queue[max],dftrav[max];
int n,f=-1,r=-1,k=0;

int isEmpty()
{
    if(f==-1 || f>r)
        return 1;
    else
        return 0;
}

void print()
{
    int i;
    printf("\n\n\nDepth First Search is :: ");
    for(i=0;i<k;i++)
        printf("%4c",dftrav[i]+65);
    printf("\n");
}

void dfs(int w)
{
    int i,u;
    struct graph *temp;
    for(i=0;i<n;i++)
        visited[i]=0;
    if(f==-1 && r==-1)
	{
        ++f;
        queue[++r]=w;
    }
    dftrav[k++]=queue[r];
    visited[w]=1;
    while(!isEmpty())
	{
        u=queue[f++];
        temp=head[u];
        while(temp!=NULL)
		{
            w=temp->data;
            if(!visited[w])
			{
                queue[++r]=w;
                dftrav[k++]=queue[r];
                visited[w]=1;
            }
            temp=temp->next;
        }
    }
}

int main()
{
    int i,j,x;
    struct graph *temp;
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL)
	{
        printf("\nCan't open file...");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
	{
        head[i]=NULL;
        for(j=0;j<n;j++)
		{
            fscanf(fp,"%d",&x);
            if(x==1)
			{
                temp=head[i];
                p=(struct graph*)malloc(sizeof(struct graph));
                if(p==NULL) 
				{
                    printf("Can't allocate memory...\n");
                    exit(1);
                }
                p->data=j;
                p->next=NULL;
                if(head[i]==NULL)
                    head[i]=p;
                else 
				{
                    while(temp->next!=NULL)
                        temp=temp->next;
                    temp->next=p;
                }
            }
        }
    }
    fclose(fp);
    printf("\nThe graph is displayed in adjacency list ::\n");
    for(i=0;i<n;i++)
	{
        temp=head[i];
        printf("\n%c -> ",i+65);
        while(temp!=NULL)
		{
            printf("%c ",temp->data+65);
            temp=temp->next;
        }
    }
    dfs(0);
    print();
    return 0;
}
