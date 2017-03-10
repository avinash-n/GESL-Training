#include"header.h"

void pop(int *top)
{
	int num;
	if (*top == MIN) {
		printf("stack is empty\n\n");
	} else {
		num = stack[(*top)--];
	}
}
