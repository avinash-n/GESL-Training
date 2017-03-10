// Implimentation of quick sort algorithm

// User defined header file
#include "sort.h"

#define SWAP1(a, b) a = a + b;\
		    b = a - b;\
		    a = a - b;

void quick_sort(int arr[], int low, int high) {
	int pivot;
	int i;
	int j;

	if (low < high) {
		pivot = low;
		i = low;
		j = high;
		while (i < j) {
			while ((arr[i] <= arr[pivot]) && (i <= high)) {
				i++;
			}

			while ((arr[j] > arr[pivot]) && (j>= low)) {
				j--;
			}

			if (i < j) {
				SWAP1(arr[i], arr[j]);
			}
		}
		SWAP1(arr[j], arr[pivot]);
		quick_sort(arr, low, j-1);
		quick_sort(arr, j+1, high);
	}
}

int quick(int num_ele, int sort_order) {
	char *temp = NULL;
	int i;

	MEM_ALLOC(temp);
	VALIDATE_MEM_ALLOC(temp);

	READ_ARRAY;

	quick_sort(arr, 0, num_ele);

	printf("Elements after sorting:\n");
	if (sort_order == 1) {
		for (i = 1; i <= num_ele; i++) {
			printf("%d\t", arr[i]);
		}
	} else if (sort_order == 2) {
		for (i = num_ele; i >= 1; i--) {
			printf("%d\t", arr[i]);
		}
	}

	printf("\n");

	return 0;
}
