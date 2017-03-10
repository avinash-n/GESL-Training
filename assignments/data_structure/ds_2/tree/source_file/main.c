/* Lab test 4
 * Program: Binary search tree
 * Functions:
	1. Insert child to create tree
	2. Display tree in pre-order
	3. Delete a parent having only one child
 */

#include "myheader.h"

int main(void) {
	char *opt;
	MEM_ALLOC(opt);
	VALIDATE_MEM_ALLOC(opt);
	
	root = NULL;
	MEM_ALLOC_S(root);
	VALIDATE_MEM_ALLOC(root);

	printf("----BINARY SEARCH TREE----\n");
	while (1) {
		printf("Select the operation to perform:\n");
		printf("1. Insert\n2. Display\n3. Delete\n4. Exit\n");
		fgets(opt, NUM_LENGTH, stdin);

		switch (my_atoi(opt)) {
		case 1:
			create_child();
			break;
		case 2:
			if (root) {
				display_tree(root);
			} else {
				printf("Tree doesn't exist\n");
			}
			break;
		case 3:
			delete_node();
			break;
		case 4:
			printf("Program is closed\n");
			exit(0);
		default:
			printf("Invalid input!\n");
		}
	}

	return 0;
}
