// Merge sorting algorithm

#include "sort.h" 

int arr_b[100];

void merge_arr(int arr[], int order, int low, int mid, int high) {
	int l1 = low;
	int l2 = mid + 1;
	int i = 0;
	int j = 0;

	while ((l1 <= mid) && (l2 <= high)) {
		if (order == 1) {
			if (arr[l1] < arr[l2]) {
				arr_b[i++] = arr[l1++];
			} else {
				arr_b[i++] = arr[l2++];
			}
		} else if (order == 2) {
			if (arr[l1] > arr[l2]) {
				arr_b[i++] = arr[l1++];
			} else {
				arr_b[i++] = arr[l2++];
			}
		}
	}

	while (l1 <= mid) {
		arr_b[i++] = arr[l1++];
	}

	while (l2 <= high) {
		arr_b[i++] = arr[l2++];
	}

	for (i = low, j = 0; i <= high; i++, j++ )
		arr[i] = arr_b[j];
}

void merge_sort(int arr[], int sort_order, int low, int high) {
	int mid;

	if (low < high) {
		mid = (low + high) / 2;
		merge_sort(arr, sort_order, low, mid);
		merge_sort(arr, sort_order, (mid + 1), high);

		merge_arr(arr, sort_order, low, mid, high);
	} else {
		return;
	}
}

int merge (int num_ele, int sort_order) {
	char *temp = NULL;
	int i;

	MEM_ALLOC(temp);
	VALIDATE_MEM_ALLOC(temp);

	READ_ARRAY;

	merge_sort(arr, sort_order, 0, num_ele);
	
	printf("Array after sorting:\n");
	if (sort_order == 1) {
		for (i = 1; i <= num_ele; i++) {
			printf("%d\t", arr[i]);
		}
	} else if (sort_order == 2) {
		for (i = 0; i < num_ele; i++) {
			printf("%d\t", arr[i]);
		}
	}

	printf("\n");

	return 0;
}
