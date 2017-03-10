// Function to insert a child into tree

#include "myheader.h"

void insert_child(CHILD *create) {
	CHILD *temp = NULL;
	MEM_ALLOC_S(temp);
	VALIDATE_MEM_ALLOC(temp);

	temp = root;

	if (temp == NULL) {
		root = create;
	} else {
		while (1) {
			if ((temp -> data) > (create -> data)) {
				if ((temp -> r_child) == NULL) {
					temp -> r_child = create;
					break;
				} else {
					temp = temp -> r_child;
				}
			} else {
				if ((temp -> l_child) == NULL) {
					temp -> l_child = create;
					break;
				} else {
					temp = temp -> l_child;
				}
			}
		}
	}
}		
