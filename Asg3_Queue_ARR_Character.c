//Character Linear Queue

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4
char queue[MAXSIZE], n = 0, q, queuefront = -1, queuerear = -1;
void enquque(char v)
{
	queue[++queuerear] = v;
	if (queuefront == -1)
	{
		queuefront = queuefront + 1;
	}
}
char delquque()
{
	char d = queue[queuefront++];
	return d;
}
void traversal()
{
	printf("\n\nWatch The Elements: ");
	int i = 0;
	if ((queuefront == -1) || (queuefront > queuerear))
	{
		printf(" Queue Is Empty\n");
		return;
	}
	for (i = queuefront; i <= queuerear; i++)
	{
		printf("%c ", queue[i]);
	}
	printf("\n");
}
int main()
{
	int c = 0;
	char e, p;
	do
	{
		printf("\nAdd A Character(1) \\ Delete An Character(2) \\ Display(3) \\ Exit(4) \nEnter Your Choice: ");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			if (queuerear == sizeof(queue) - 1)
			{
				printf("\nQueue Overflow\n");
			}
			printf("\nEnter The Character You Want To Add: ");
			scanf(" %c", &e);
			enquque(e);
			traversal();
			break;
		case 2:
			if (((queuefront == -1)))
			{
				printf("\nQueue Underflow\n");
			}
			else
			{
				printf("\nDeleting An Character ");
				traversal();

				printf("\nThe Deleted Character Is: %c", delquque());
				traversal();
			}
			break;
		case 3:
			traversal();
			break;
		case 4:
			printf("\nThank You");
			exit(0);
		default:
			printf("\nEnter A Correct Option\n");
		}
	} while (1);
	return 0;
}