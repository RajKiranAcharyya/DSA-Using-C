#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} sll;
sll *head = NULL;

void push(int data)
{
	sll *newnode = (sll *)malloc(sizeof(sll));
	if (newnode == NULL)
	{
		printf("\nMemory Is Full");
		return;
	}
	newnode->data = data;
	newnode->next = head;
	head = newnode;
}

int pop()
{
	sll *t = head;
	int k = head->data;
	head = head->next;
	free(t);
	return k;
}

void display()
{
	if (head == NULL)
	{
		printf("\nEmpty STACK");
		return;
	}
	printf("\nCurrent STACK: ");
	sll *traverse = head;
	while (traverse != NULL)
	{
		printf("%d", traverse->data);
		if (traverse->next != NULL)
		{
			printf("->");
		}
		traverse = traverse->next;
	}
}

int main()
{
	int p = 0, a = 0;
	while (1)
	{
		printf("\nPUSH(1) / POP(2) / DISPLAY(3): ");
		scanf("%d", &p);
		switch (p)
		{
		case 1:
			printf("\nEnter Data: ");
			scanf("%d", &a);
			push(a);
			display();
			break;
		case 2:
			if (head == NULL)
			{
				printf("\nEmpty STACK");
			}
			else
			{
				printf("\nThe Popped Value Is: %d", pop());
				display();
			}
			break;
		case 3:
			if (head == NULL)
			{
				printf("\nEmpty STACK");
			}
			else
				display();
			break;
		default:
			printf("\nEnter The Correct Option");
		}
	}
	return 0;
}
