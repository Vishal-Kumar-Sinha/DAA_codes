#include<stdio.h>
#include<stdlib.h>
#define max 100

int n;

struct graph {
    int data;
    struct graph *next;
}*head[max], *p;

int main() {
    struct graph *temp;
    FILE *fp;
    int i, j, x;
    fp = fopen("graph.txt", "r");
    if(fp == NULL) {
        printf("Cannot open file...\n");
        exit(1);
    }
    fscanf(fp, "%d", &n);
    for(i = 0; i < n; i++) {
        head[i] = NULL;
        for(j = 0; j < n; j++) {
            fscanf(fp, "%d", &x);
            if(x == 1) {
                temp = head[i];
                p = (struct graph *)malloc(sizeof(struct graph));
                if(p==NULL) {
                    printf("Can't allocate memory...\n");
                    exit(1);
                }
                p->data = j;
                p->next = NULL;
                if(head[i] == NULL)
                    head[i] = p;
                else {
                    while(temp->next != NULL)
                        temp = temp->next;
                    temp->next = p;
                }
            }
        }
    }
    fclose(fp);
    printf("Adjacency list :: \n\n");
    for(i = 0; i < n; i++) {
        temp = head[i];
        printf("Adjacent of vertex %c :: ", i+65);
        while(temp != NULL) {
            printf("%c ", temp->data+65);
            temp = temp->next;
        }
        printf("\n");
    }
    return 0;
}
