#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} sll;
sll *head = NULL;
sll *m = NULL;
void enqueue(int data)
{
	sll *newnode = (sll *)malloc(sizeof(sll));
	if (newnode == NULL)
	{
		printf("\nMemory Is Full");
		return;
	}
	newnode->data = data;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		m = head;
		while (m->next != NULL)
		{
			m = m->next;
		}
		m->next = newnode;
	}
}
int delqueue()
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
		printf("\nEmpty QUEUE");
		return;
	}
	printf("\nCurrent QUEUE: ");
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
		printf("\nENQUEUE(1) / DELQUEUE(2) / DISPLAY(3): ");
		scanf("%d", &p);
		switch (p)
		{
		case 1:
			printf("\nEnter Data: ");
			scanf("%d", &a);
			enqueue(a);
			display();
			break;
		case 2:
			if (head == NULL)
			{
				printf("\nQUEUE Underlow");
			}
			else
			{
				printf("\nThe Delqueued Value Is: %d", delqueue());
				display();
			}
			break;
		case 3:
			display();
			break;
		default:
			printf("\nEnter The Correct Option");
		}
	}
	return 0;
}
