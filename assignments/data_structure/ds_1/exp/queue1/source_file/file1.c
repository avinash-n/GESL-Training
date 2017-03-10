/* Program to implement queue */

#include "myheader.h"

int main()
{
	char *opt;
	int option;

	MEM_ALLOC(opt);
	VALIDATE_MALLOC(opt);

	printf("--------QUEUE OPERATIONS--------\n");

	do {
		printf("Available queue operations:\n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Clear\n");
		printf("Select the operation: ");
		opt = fgets(opt, NUM_SIZE, stdin);

		option = validate(opt);

		switch (option) {
		case enqueue:
			enq();
			break;
		case dequeue:
			deq();
			break;
		case display:
			disp();
			break;
		case clear:
			printf("The queue is released\n");
			exit(0);
		default:
			printf("***Please select the valid option***\n");
			break;
		}
	} while (1);

	return 0;
}
