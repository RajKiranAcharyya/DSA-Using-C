#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4
int stack[MAX_SIZE], stacktop = -1;
void push(int v)
{
	stack[++stacktop] = v;
}
int pop()
{
	return stack[stacktop--];
}
void traversal()
{
	printf("\nWatch The Elements: ");
	int i = 0;
	if (stacktop == -1)
	{
		printf(" Stack Is Empty\n");
		return;
	}
	for (i = stacktop; i > -1; i--)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}
int main()
{
	int c = 0, e = 0, p = 0;
	do
	{
		printf("Add An Element(1) / Delete An Element(2) / Display(3) / Exit(4) \nEnter Your Choice: ");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			if (stacktop == MAX_SIZE - 1)
			{
				printf("\nStack Overflow\n");
			}
			else
			{
				printf("\nEnter The Element You Want To Add: ");
				scanf("%d", &e);
				push(e);
				traversal();
			}
			break;
		case 2:
			if (stacktop == -1)
			{
				printf("\nStack Underflow\n");
			}
			else
			{
				printf("\nDeleting An Element ");
				traversal();
				printf("\nThe Deleted Element Is: %d", pop());
				traversal();
			}
			break;
		case 3:
			traversal();
			break;
		case 4:
			exit(0);
			//break;
		default:
			printf("\nEnter A Correct Option\n");
		}
	} while (1);
	return 0;
}