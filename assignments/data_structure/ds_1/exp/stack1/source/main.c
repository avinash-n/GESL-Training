#include "header.h"

int main()
{
	char *cs;
	int  cs1;
	int *top;
	*top = MIN;

	if(NULL == (cs = (char *) malloc(sizeof(char)*MAX))) {
		printf("malloc is not allocated\n");
	}

	while(1) {	
	printf("Enter the case\n");
	printf("Enter 1 for PUSH operation\n");
	printf("Enter 2 for POP operation\n");
	printf("Enter 3 for displaying the contents of stack\n");
	printf("Enter 4 to exit from stack operations\n");
	printf("your option is: ");
	fgets(cs, MAX, stdin);

	cs1 = asciitoint(cs);

	switch (cs1) {
	case 1:
			push(top);
			break;
	case 2 :
			pop(top);
			break;
	case 3 :
			display(top);
			break;
	case 4 :
			exit(0);
			break;

	default :
			printf("Enter proper case");
			break;

	
	}
	}
}
