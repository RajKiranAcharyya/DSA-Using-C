#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

void binarysearch(int a[], int l, int r, int s)
{
	int counter_binary = 0;
	while (l <= r) // Fix condition to allow l == r
	{
		counter_binary++;
		int m = (l + r) / 2;
		if (a[m] == s)
		{
			printf("%d Is Found At Index %d\n", s, m);
			printf("Counter_Binary=%d\n", counter_binary);
			return;
		}
		else if (s > a[m])
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	printf("%d Is Not Found\nCounter_Binary=%d\n", s, counter_binary);
}

void interpolationsearch(int a[], int l, int r, int s)
{
	int counter_interpolation = 0;
	while (l <= r && s >= a[l] && s <= a[r]) // Ensure s is within bounds of array
	{
		counter_interpolation++;
		if (l == r)
		{
			if (a[l] == s)
			{
				printf("%d Is Found At Index %d\n", s, l);
			}
			else
			{
				printf("%d Is Not Found\n", s);
			}
			printf("Counter_Interpolation=%d\n", counter_interpolation);
			return;
		}

		// Avoid division by zero
		if (a[l] == a[r])
			break;

		// Probing position
		int m = l + ((s - a[l]) * (r - l)) / (a[r] - a[l]);

		// Check if m is out of bounds
		if (m < l || m > r)
			break;

		if (a[m] == s)
		{
			printf("%d Is Found At Index %d\n", s, m);
			printf("Counter_Interpolation=%d\n", counter_interpolation);
			return;
		}
		else if (s > a[m])
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	printf("%d Is Not Found\nCounter_Interpolation=%d\n", s, counter_interpolation);
}

int main()
{
	int a[maxsize], n = 0;
	int i = 0, s = 0, c = 0;
	printf("\nEnter The Size Of The Array: ");
	scanf("%d", &n);
	printf("\nEnter The Elements\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	while (1)
	{
		printf("\nEnter The Element To Be Searched: ");
		scanf("%d", &s);
		printf("Enter The Searching Method: Binary(1) Or Interpolation(2): ");
		scanf("%d", &c);
		if (c == 1)
		{
			binarysearch(a, 0, n - 1, s);
		}
		else if (c == 2)
		{
			interpolationsearch(a, 0, n - 1, s);
		}
		else
		{
			printf("\nEnter Correct Option\n");
		}
	}
	return 0;
}
