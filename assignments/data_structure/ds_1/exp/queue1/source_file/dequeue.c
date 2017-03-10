/* Function to dequeue data elements */

#include "myheader.h"

void deq(void)
{
	if (((rear - 1) == -1) || ((front - 1) >= MAX_QUEUE_LENGTH)) {
		printf("Queue is empty!\n");
	} else {
		printf("Dequeued element is : %d\n", queue[front]);
		front++;
	}
}
