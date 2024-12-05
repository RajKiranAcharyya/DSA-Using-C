#include <stdio.h>
#include <stdlib.h>
int a[30], n = 0;
void traversal()
{
	int i = 0;
	printf("\nWatch The Array: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}
void insert(int p, int v)
{
	int i = 0;
	for (i = n - 1; i >= p; i--)
	{
		a[i + 1] = a[i];
	}
	a[p] = v;
	n++;
}
void deletion(int p)
{
	int i = 0;
	for (i = p; i <= n - 2; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void search(int v)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == v)
		{
			printf("\nWatch The Position Of The Value: %d", i + 1);
			break;
		}
	}
	if (i == n)
	{
		printf("\nElement Not Found");
	}
}
void replace(int p, int v)
{
	a[p - 1] = v;
}
int main()
{
	int p = 0, v = 0, i = 0;
	char c;
	printf("\nEnter The No. Of Elements: ");
	scanf("%d", &n);
	printf("\nEnter The Elements: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	while (1)
	{
		printf("\n\t\t\t\t\t  ---Array Operations Menu---\nChoose Option(Insert A Element(1) / Delete A Element(2) / Replace An Element(3) / Search An Element(4) / Watch Array(5) / Exit(6)): ");
		int c, b;
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("\nChoose Option (Insert At Beginning(7) / Insert At End(8) / Insert At Other Position(9)): ");
			scanf("%d", &b);
			switch (b)
			{
			case 7:
				printf("\nEnter The Value: ");
				scanf("%d", &v);
				insert(0, v);
				traversal();
				break;
			case 8:
				printf("\nEnter The Value: ");
				scanf("%d", &v);
				insert(n, v);
				traversal();
				break;
			case 9:
				printf("\nEnter The Position: ");
				scanf("%d", &p);
				printf("\nEnter The Value: ");
				scanf("%d", &v);
				insert(--p, v);
				traversal();
				break;
			default:
				printf("\nEnter Correct Insertion Option");
				break;
			}
			break;
		case 2:
			printf("\nChoose Option (Delete At Beginning(7) / Delete At End(8) / Delete At Other Position(9)): ");
			scanf("%d", &b);
			switch (b)
			{
			case 7:
				deletion(0);
				traversal();
				break;
			case 8:
				deletion(n);
				traversal();
				break;
			case 9:
				printf("\nEnter The Position: ");
				scanf("%d", &p);
				deletion(--p);
				traversal();
				break;
			default:
				printf("\nEnter Correct Insertion Option");
				break;
			}
			break;
		case 3:
			printf("\nEnter The Position To Replace: ");
			scanf("%d", &p);
			printf("\nEnter The New Value: ");
			scanf("%d", &v);
			replace(p, v);
			traversal();
			break;
		case 4:
			printf("\nEnter The Value To Search: ");
			scanf("%d", &v);
			search(v);
			break;
		case 5:
			traversal();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("\nEnter Correct Option");
		}
	}
	return 0;
}