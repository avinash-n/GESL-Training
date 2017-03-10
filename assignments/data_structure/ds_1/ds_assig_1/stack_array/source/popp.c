
#include "header.h"

void pop(void)
{
	int element;
	
	if(top == -1)
		printf("stack is empty\n");
	else {
		element = stack[top];
		top--;
	}
} 
		
