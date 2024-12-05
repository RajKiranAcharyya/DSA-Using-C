#include <stdio.h>
#include <stdlib.h>
int queue[100],n=0,q,queuefront=-1,queuerear=-1;
void enquque(int v)
{
	if(queue == NULL)return;
	if(queuerear == sizeof(queue)-1)
	{
		printf("\nQueue Overflow\n");
	}
	else
	{
		queue[++queuerear]=v;
		if(queuefront == -1)
		{
			queuefront++;
		}
	}
}
int delquque()
{
	if(queue == NULL)return;
	if(queuefront == -1)
	{
		printf("\nQueue Underflow\n");
		return -1;
	}
	else
	{
		return queue[queuefront++];
	}
}
void traversal()
{
    if(queue == NULL)return;
	printf("\nWatch The Elements: ");
	int i=0;
	if(queuefront == -1)
	{
		printf(" Queue Is Empty\n");
		return;
	}
	for(i=queuefront; i<=queuerear; i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}
int main()
{
	int c=0,e=0;
	do
	{
		printf("Add An Element(1) \\ Delete An Element(2) \\ Display(3) \\ Exit(4) \nEnter Your Choice: ");
		scanf("%d",&c);
		switch(c)
			{
				case 1:printf("\nEnter The Element You Want To Add: ");
				      scanf("%d",&e);
				      enquque(e);
				      traversal();
				      break;
			    case 2:printf("\nDeleting An Element: ");
				       traversal();
				       printf("\nThe Deleted Element Is: %d",delquque());
				       traversal();
				       break;
			    case 3:traversal();
				       break;
		        case 4:exit(0);
		               break;
		      default:printf("\nEnter A Correct Option\n");
			}
	}while(1);
	return 0;
}
