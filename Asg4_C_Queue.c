//Circular Queue

#include <stdio.h>
#include <stdlib.h>
#define maxsize 4

int cqueue[maxsize], cqueuefront = -1, cqueuerear = -1;

void cenqueue(int a)
{
    if (cqueuefront == -1)
    {
        cqueuefront = cqueuerear = 0;
    }
    else
    {
        cqueuerear = (cqueuerear + 1) % maxsize;
    }
    cqueue[cqueuerear] = a;
}

int cdelqueue()
{
    int d = cqueue[cqueuefront];
    if (cqueuefront == cqueuerear)
    {
        cqueuefront = cqueuerear = -1; // Queue becomes empty
    }
    else
    {
        cqueuefront = (cqueuefront + 1) % maxsize;
    }
    return d;
}

void display()
{
    int i;
    printf("\nWatch The Array: ");
    if (cqueuefront <= cqueuerear)
    {
        for (i = cqueuefront; i <= cqueuerear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    else
    {
        for (i = cqueuefront; i < maxsize; i++)
        {
            printf("%d ", cqueue[i]);
        }
        for (i = 0; i <= cqueuerear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
}

int main()
{
    int a, b;
    printf("Add An Element = INSERT\nDelete An Element = DELETE\n");
    while (1)
    {
        printf("\n\nINSERT(1)/DELETE(2)/DISPLAY(3)/EXIT(4)\nEnter Your Choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            if ((cqueuerear + 1) % maxsize == cqueuefront)
            {
                printf("\nQueue Overflow");
            }
            else
            {
                printf("\nEnter The Element: ");
                scanf("%d", &b);
                cenqueue(b);
            }
            break;
        case 2:
            if (cqueuefront == -1)
            {
                printf("\nQueue Underflow");
            }
            else
            {
                printf("\nDeleting An Element");
                printf("\nThe Deleted Element Is: %d\n", cdelqueue());
            }
            break;
        case 3:
            if (cqueuefront == -1)
            {
                printf("\nQueue Is Empty");
            }
            else
            {
                display();
            }
            break;
        case 4:
            printf("\nThank You");
            exit(0);
            break;
        default:
            printf("\nEnter A Correct Option");
        }
    }
    return 0;
}
