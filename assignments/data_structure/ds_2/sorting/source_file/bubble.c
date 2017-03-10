// Bubble sorting algorithm

#include "sort.h"

int bubble (int num_ele, int sort_order) {
	char *temp = NULL;
	int i;
	int j;

	MEM_ALLOC(temp);
	VALIDATE_MEM_ALLOC(temp);

	READ_ARRAY;
	for (i = 0; i < (num_ele - 1); i++) {
		for (j = 0; j < (num_ele - i - 1); j++) {
			if ((sort_order == 1) && (arr[j] > arr[j + 1])) {
				SWAP;
			} else if ((sort_order == 2) && (arr[j] < arr[j + 1])) {
				SWAP;
			}
		}
	}
	
	PRINT_ARRAY;
	printf("\n");

	return 0;
}
