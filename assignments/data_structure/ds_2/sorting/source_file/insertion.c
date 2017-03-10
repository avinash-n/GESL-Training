// Bubble sorting algorithm

#include "sort.h"

#define XCHG arr[j + 1] = arr[j];\
	     arr[j] = min;

int insertion (int num_ele, int sort_order) {
	char *temp = NULL;
	int i;
	int j;
	int min;

	MEM_ALLOC(temp);
	VALIDATE_MEM_ALLOC(temp);

	READ_ARRAY;
	for (i = 1; i < num_ele; i++) {
		min = arr[i];
		for (j = (i - 1); j >= 0; j--) {
			if ((sort_order == 1) && (arr[j] > min)) {
				XCHG;
			} else if ((sort_order == 2) && (arr[j] < min)) {
				XCHG;
			} else {
				break;
			}
		}
	}

	PRINT_ARRAY;
	printf("\n");

	return 0;
}
