// Function to create a child

#include "myheader.h"

void create_child(void) {
	char *ele = NULL;
	MEM_ALLOC(ele);
	VALIDATE_MEM_ALLOC(ele);
	
	CHILD *create = NULL;
	MEM_ALLOC_S(create);
	VALIDATE_MEM_ALLOC(create);

	printf("Enter the element:\n");
	fgets(ele, NUM_LENGTH, stdin);

	create->data = my_atoi(ele);
	create->l_child = NULL;
	create->r_child = NULL;

	insert_child(create);
}
