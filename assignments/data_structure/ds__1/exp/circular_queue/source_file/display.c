/* Function to display elements of queue */

#include "myheader.h"

void disp(void)
{
	int i;

	if ((front == rear) && (count == 0)) {
		printf("Queue is empty!\n");
	} else {
		printf("Elements of queue are:\n");

		for (i = (rear - 1); i >= front; i--) {
            		printf("%d\t", queue[i]);
		}

		printf("\n");
	}
}
