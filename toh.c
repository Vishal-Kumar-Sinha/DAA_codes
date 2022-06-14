/*Write a program to implement Tower of Hanoi Problem.*/

#include<stdio.h>
void TOH(int ,char ,char ,char );
int main()
{
	int n;
	printf("\nEnter the number of disk: ");
	scanf("%d",&n);
	printf("\n\n");
	TOH(n,'A','B','C');
	return 0;
}
void TOH(int n,char source,char intermediate,char destination)
{
	if(n==1)
	{
		printf("Move disk %d from rod %c to rod %c\n",n,source,destination);
		return;
	}
	else{
		TOH(n-1,source,destination,intermediate);
	    printf("Move disk %d from rod %c to rod %c\n",n,source,destination);
	    TOH(n-1,intermediate,source,destination);
	}
}
