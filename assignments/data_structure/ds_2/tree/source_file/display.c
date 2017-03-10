// Function to display the tree elements

#include "myheader.h"

void pre_order(CHILD *temp) {
	if (temp != NULL) {
		printf("%d\n", temp->data);
		pre_order(temp->r_child);
		pre_order(temp->l_child);
	}
}

void in_order(CHILD *temp) {
	if (temp != NULL) {
		in_order(temp->r_child);
		printf("%d\n", temp->data);
		in_order(temp->l_child);
	}
}

void post_order(CHILD *temp) {
	if (temp != NULL) {
		post_order(temp->r_child);
		post_order(temp->l_child);
		printf("%d\n", temp->data);
	}
}

void display_tree(CHILD *temp) {
	char *order;
	MEM_ALLOC(order);
	VALIDATE_MEM_ALLOC(order);

	printf("Enter the order of traversal:\n");
	printf("1. Pre-order\n2. In-order\n3. Post-order\n4. Level order\n");
	fgets(order, NUM_LENGTH, stdin);

	switch (my_atoi(order)) {
	case 1:
		pre_order(temp);
		break;
	case 2:
		in_order(temp);
		break;
	case 3:
		post_order(temp);
		break;
/*	case 4:
		level_order(temp);
		break;
*/	default:
		printf("Invalid input!\n");
	}
}
