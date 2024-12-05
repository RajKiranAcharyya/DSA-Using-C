#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertAtBeginning(int data)
{
	struct Node *newNode = createNode(data);
	newNode->next = head;
	head = newNode;
}

void insertAtEnd(int data)
{
	struct Node *newNode = createNode(data);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	struct Node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertAtPosition(int data, int pos)
{
	struct Node *newNode = createNode(data);
	if (pos == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	struct Node *temp = head;
	for (int i = 1; i < pos - 1 && temp != NULL; i++)
	{
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteFromBeginning()
{
	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	struct Node *temp = head;
	head = head->next;
	free(temp);
}

void deleteFromEnd()
{
	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	if (head->next == NULL)
	{
		free(head);
		head = NULL;
		return;
	}
	struct Node *temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void deleteAtPosition(int pos)
{
	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	if (pos == 1)
	{
		struct Node *temp = head;
		head = head->next;
		free(temp);
		return;
	}
	struct Node *temp = head;
	struct Node *prev = NULL;
	for (int i = 1; i < pos && temp != NULL; i++)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}

void traverseList()
{
	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	printf("List elements: ");
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		if (temp->next != NULL)
			printf("->");
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int choice, data, pos;
	printf("\n--- Menu ---\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Delete from Beginning\n5.Delete from End\n6.Delete at Position\n7.Traverse List\n8.Exit\n");
	while (1)
	{
		print("\nEnter Choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter data: ");
			scanf("%d", &data);
			insertAtBeginning(data);
			break;
		case 2:
			printf("Enter data: ");
			scanf("%d", &data);
			insertAtEnd(data);
			break;
		case 3:
			printf("Enter data: ");
			scanf("%d", &data);
			printf("Enter position: ");
			scanf("%d", &pos);
			insertAtPosition(data, pos);
			break;
		case 4:
			deleteFromBeginning();
			break;
		case 5:
			deleteFromEnd();
			break;
		case 6:
			printf("Enter position: ");
			scanf("%d", &pos);
			deleteAtPosition(pos);
			break;
		case 7:
			traverseList();
			break;
		case 8:
			return 0;
		default:
			printf("Invalid choice! Try again.\n");
		}
		if (choice != 7)
			traverseList();
	}
}
