#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100

char stack[maxsize];
int n = 0, stacktop = -1;

void push(char v)
{
	if (stacktop == maxsize - 1)
	{
		printAf("\nStack Overflow\n");
	}
	else
	{
		stack[++stacktop] = v;
	}
}

char pop()
{
	if (stacktop == -1)
	{
		printf("\nStack Underflow\n");
		return '@';
	}
	else
	{
		return stack[stacktop--];
	}
}

int precedence(char a)
{
	switch (a)
	{
	case '^':
		return 3;
	case '*':
	case '%':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

int isoperator(char a)
{
	return (a == '+' || a == '-' || a == '*' || a == '/' || a == '%' || a == '^');
}

int isopeningbracket(char a)
{
	return (a == '(' || a == '{' || a == '[');
}

int isclosingbracket(char a)
{
	return (a == ')' || a == '}' || a == ']');
}

int main()
{
	int c = 0;
	char e = 0;
	int i = 0, j = 0;
	char infix[maxsize], postfix[maxsize];

	printf("\nEnter The INFIX Statement: ");
	fgets(infix, maxsize, stdin);

	int len = strlen(infix);
	if (infix[len - 1] == '\n')
	{
		infix[len - 1] = ']';
		len++;
		infix[len - 1] = '\0';
	}
	stack[++stacktop] = '[';
	for (i = 0; infix[i]; i++)
	{
		if (isopeningbracket(infix[i]))
		{
			push(infix[i]);
		}
		else if (isclosingbracket(infix[i]))
		{
			while (stacktop != -1 && !isopeningbracket(stack[stacktop]))
			{
				postfix[j++] = pop();
			}
			pop();
		}
		else if (isoperator(infix[i]))
		{
			while (stacktop != -1 && isoperator(stack[stacktop]) && precedence(infix[i]) <= precedence(stack[stacktop]))
			{
				postfix[j++] = pop();
			}
			push(infix[i]);
		}
		else
		{
			postfix[j++] = infix[i];
		}
	}
	while (stacktop != -1)
	{
		if (isopeningbracket(stack[stacktop]))
		{
			printf("INVALID Expression");
			break;
		}
		postfix[j++] = pop();
	}

	if (stacktop == -1)
	{
		postfix[j] = '\0';
		printf("Postfix Expression: %s\n", postfix);
	}
	return 0;
}