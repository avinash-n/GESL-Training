// this function pushes the value to stack[top]

#include"header.h" 

void push(int *top)
{
	int num;
	
	printf("Enter the value to push\n"); // value to be pushed
	scanf("%d",&num);

	if (*top == MAX) {
		printf("stack is full\n\n");
	} else {
		stack[++(*top)] = num;
	}	
		
}
