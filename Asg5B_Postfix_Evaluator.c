#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100
int stack[maxsize];
int n = 0, stacktop = -1;
void push(int v)
{
    if (stacktop == maxsize - 1)
    {
        printf("\nStack Overflow\n");
        return;
    }
    else
    {
        stack[++stacktop] = v;
    }
}
int pop()
{
    if (stacktop == -1)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    {
        return stack[stacktop--];
    }
}
int isoperator(char a)
{
    return (a == '+' || a == '-' || a == '*' || a == '/' || a == '%' || a == '^');
}
int calculate(int b, char x, int a)
{
    switch (x)
    { 
    case '^':
        return pow(b, a);
    case '*':
        return b * a;
    case '%':
        return b % a;
    case '/':
        return b / a;
    case '+':
        return b + a;
    case '-':
        return b - a;
    default:
        return 0;
    }
}
int main()
{
    int i = 0, a = 0, b = 0, c = 0;
    char postfix[maxsize];
    printf("\nEnter The POSTFIX Expression: ");
    fgets(postfix, maxsize, stdin);
    int len = strlen(postfix);
    if (postfix[len - 1] == '\n')
    {
        postfix[len - 1] = '\0';
    }
    for (i = 0; postfix[i]; i++)
    {
        if (isoperator(postfix[i]))
        {
            a = pop();
            b = pop();
            c = calculate(b, postfix[i], a);
            push(c);
        }
        else
        {
            push(postfix[i] - '0'); // Manual Conversion       Not TYPECASTING
                                    // Diff matter
        }
    }
    printf("%d ", pop());
    return 0;
}

/*
Why postfix[i] - '0' is used:
Characters in C are stored as their ASCII values. For example:

'0' has an ASCII value of 48.
'5' has an ASCII value of 53.
To convert the character '5' into its numeric value 5, you subtract '0' from it:

c
Copy code
'5' - '0' = 53 - 48 = 5
This works because the digits '0' to '9' are stored consecutively in ASCII, so subtracting '0' from any digit character gives you its numeric equivalent.

Why push((int)postfix[i]) won't work:
If you try using push((int)postfix[i]), you're just typecasting the character to its corresponding ASCII value, which doesn't solve the problem. For example:

(int)'5' will still give you 53, which is the ASCII value of the character '5', not the number 5.
You need to convert the character (e.g., '5') to the integer value it represents (e.g., 5), which is what postfix[i] - '0' does.
Typecasting vs. Manual Conversion:
Typecasting: (int)postfix[i] only changes the data type of postfix[i] from char to int, but it doesn't change the value. For instance, '5' remains 53.
Manual conversion: postfix[i] - '0' adjusts the character's value by subtracting the ASCII value of '0', thereby giving the actual number represented by the character.
*/