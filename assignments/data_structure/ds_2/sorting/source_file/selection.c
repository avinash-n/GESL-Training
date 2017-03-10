// Selction sorting algorithm

#include "sort.h"

int selection (int num_ele, int sort_order) {
	int min;
	char *temp = NULL;
	int i;
	int j;

	MEM_ALLOC(temp);
	VALIDATE_MEM_ALLOC(temp);

	READ_ARRAY;
	for (i = 0; i < (num_ele - 1); i++) {
		min = i;
		for (j = (i + 1); j < (num_ele); j++) {
			if ((sort_order == 1) && (arr[min] > arr[j])) {
				min = j;
			}
			if ((sort_order == 2) && (arr[min] < arr[j])) {
				min = j;
			}
		}
		if (arr[min] != arr[i]) {
			SWAP;
		}
	}

	PRINT_ARRAY;
	printf("\n");

	return 0;
}
