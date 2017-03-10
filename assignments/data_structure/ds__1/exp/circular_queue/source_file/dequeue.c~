/* Function to dequeue data elements */

#include "myheader.h"

void deq(void)
{
	if ((((rear - 1) == -1) || ((front - 1) >= MAX_QUEUE_LENGTH)) && (count == 0)) {
		printf("Queue is empty!\n");
	} else {
		front = front % (MAX_QUEUE_LENGTH + 1);
		printf("Dequeued element is : %d\n", queue[front++]);
		//front++;
		count--;
	}
}
