/* queue is implimented using arrays*/
#include "header.h"

int rear = -1;
int front = -1;
int limit = 5;
int queue[10];

int main()
{
	int op;
	int element;

	while(1) {
		printf("enter the op perform on queue 1.enqueue,2.dequeue,3.display4.exit\n");
		scanf("%d",&op);
		switch(op) {

			case 1:
				printf("enter the element to insert\n");
				scanf("%d",&element);
				rear = rear + 1;		
				enqueue(element, rear, limit, queue);
				break;
			case 2: 
				front = front + 1;
				element = dequeue(element, front, rear, queue);
				break;
			case 3: 
				display(front, rear, queue);
				break;
			case 4: 
				exit(1);
			default: 
				printf("enter the correct option \n");

		}
	}
}

/* void enqueue(int element,int rear,int limit, int queue[])
{
	if(rear == limit)
		printf("queue is full \n");
	else
		queue[rear] = element;
}

int dequeue(int element, int front, int rear, int queue[])
{
	if((front == -1) || (front > rear))
		printf("queue is empty \n");
	else
		element = queue[front];

	return element;
}
void display(int front, int rear, int queue[])
{
	int i = 0;
	for(i = front; i <= rear; i++)
		printf("elemnts %d\n",queue[i]);
}
*/















				
