/* Function to enqueue the data elements */

#include "myheader.h"

void enq(void)
{
	char *ele = NULL;
	MEM_ALLOC(ele);
	VALIDATE_MALLOC(ele);
		
	if ((rear >= MAX_QUEUE_LENGTH) && (count >= MAX_QUEUE_LENGTH)) {
		printf("Queue is full!\n");
	} else {
		printf("Enter the element: ");
		fgets(ele, NUM_SIZE, stdin);
		element = validate(ele);
		rear = rear % (MAX_QUEUE_LENGTH);
		queue[rear++] = element;
		count++;
	}
}
