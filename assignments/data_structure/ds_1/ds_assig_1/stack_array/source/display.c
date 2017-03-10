
#include "header.h"

void display()
{

	int i;

	if(top == -1) 
		printf("stack is empty \n");
	else{
		printf("elements in stack is \n");
		for(i = top; i > 0; i--)
		printf("%d\n",stack[i]);
	}

}
