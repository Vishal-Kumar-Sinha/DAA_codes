#include<stdio.h>
#include<stdlib.h>
#define max 100

struct graph {
    int data;
    struct graph *next;
}*head[max], *p;

int visited[max];
int n, k = 0;
void DFS(int v)
{
	struct graph*p;
    p=head[v];
    printf("%4c",v+65);
    visited[v]=1;
    while(p!=NULL)
    {
        v=p->data;
        if(!visited[v])
            DFS(v);
        p=p->next;
    }
}
int main()
{
    int i, j, x;
    struct graph *temp;
    FILE *fp;
    fp = fopen("graph.txt", "r");
    if(fp == NULL)
	{
        printf("\nCan't open file...");
        exit(1);
    }
    fscanf(fp, "%d", &n);
    for(i = 0; i < n; i++)
	{
        head[i] = NULL;
        for(j = 0; j < n; j++)
		{
            fscanf(fp, "%d", &x);
            if(x == 1)
			{
                temp = head[i];
                p = (struct graph *)malloc(sizeof(struct graph));
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
                    while(temp->next != NULL)
                        temp = temp->next;
                    temp->next = p;
                }
            }
        }
    }
    fclose(fp);
    printf("\nThe graph is displayed in adjacency list ::\n");
    for(i = 0; i < n; i++)
	{
        temp = head[i];
        printf("\n%c -> ",i+65);
        while(temp != NULL)
		{
            printf("%c ", temp->data+65);
            temp = temp->next;
        }
    }
    printf("\n\nDepth First Search is :: ");
	for(i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0);
    return 0;
}
