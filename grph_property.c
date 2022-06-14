#include<stdio.h>
#include<stdlib.h>
void prompt()
{
    printf("\n------------------------------------------------------- ");
    printf("\n|| Press <1> to find the number of edges of the graph ||");
    printf("\n|| Press <2> to find the total degree of the graph    ||");
    printf("\n|| Press <3> to display the adjacent of a given vertex||");
    printf("\n|| Press <4> to display the graph                     ||");
    printf("\n|| Press <0> to exit                                  ||");
    printf("\n------------------------------------------------------- ");
}
int isAlpha(char ch)
{
    if(ch>=65 && ch<=90)
	    return 2;
	else
		return 0;
}

int degree(int** adj_mat, int n)
{
	int i,j;
	int count=0;
	for(i=0;i<=n-1;i++)
		for(j=0;j<=n-1;j++)
			if(adj_mat[i][j]==1)
				count+=1;
	return count;
}

int edges(int** adj_mat, int n)
{
	return (degree(adj_mat,n)/2);
}

void adjacent(int** adj_mat, int n, char pos)
{
	int i;
	if(isAlpha(pos)==2 && pos<n+65)
	{
		printf("\nAdjacent Vertices of %c:",pos);
		for(i=0;i<=n-1;i++)
			if(adj_mat[pos-'A'][i]==1)
				printf(" %c",('A'+i));
	}
	else
		puts("\nEnter a valid vertex...");
}

void display(int** adj_mat, int n)
{
	int i,j,k;
	puts("The Graph is stored and displayed in Adjacency Matrix Method...\n");
	for(k=0;k<=n-1;k++)
		if(k==0)
			printf("     | %c |",k+'A');
		else
			printf(" %c |",k+'A');
	printf("\n");
    for(i=0;i<=n-1;i++)
    {
    	printf("| %c  |",i+'A');
        for(j=0;j<=n-1;j++)
            printf(" %d  ",adj_mat[i][j]);
        printf("\n");
    }
}

int main()
{
    int i,j,n;
    int choice;
	char pos;
    FILE *fp;
    char file[100];
    printf("Enter file name: ");
    gets(file);
    fp=fopen(file,"r");
    if(fp==NULL)
    {
        puts("\nFile not found");
        exit(0);
    }
    fscanf(fp,"%d",&n);
    int** graph=(int **)malloc(n*sizeof(int *));
    for(i=0;i<=n-1;i++)
        graph[i]=(int *)malloc(n*sizeof(int));
    for(i=0;i<=n-1;i++)
        for(j=0;j<=n-1;j++)
            fscanf(fp,"%d",&graph[i][j]);
    do
    {
        prompt();
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
                    break;
            case 1: puts("\nThe graph is assumed to be a Undirected Graph...");
					printf("\nNumber of edges of the graph: %d",edges(graph,n));
                    break;
            case 2: puts("\nThe graph is assumed to be a Undirected Graph...");
					printf("\nTotal degree of the graph: %d",degree(graph,n));
                    break;
            case 3: getchar();
					printf("\nEnter the vertex to find the adjacent vertices: ");
                    scanf("%c",&pos);
                    pos=toupper(pos);
                    adjacent(graph,n,pos);
                    break;
            case 4: display(graph,n);
                    break;
            default: printf("\nEnter a valid choice...");
        }
    }
    while(choice!=0);
    fclose(fp);
    return 0;
}
