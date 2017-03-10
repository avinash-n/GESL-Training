#include"header.h"

void display(int *top)
{	
	int i = *top;

	while(i != MIN) {
		printf("%d\n", stack[(*top) - i]);
		i--;
	}
	if(i == MIN) {
		printf("stack is empty and there is no further element to display\n");
	}
}
