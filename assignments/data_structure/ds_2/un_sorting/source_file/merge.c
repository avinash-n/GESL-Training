// Merge sorting algorithm

#include <stdio.h>
#include <stdlib.h>

int arr_a[100];
int arr_b[100];
int order;

void merge_arr(int arr[], int low, int mid, int high) {
	int l1 = low;
	int l2 = mid + 1;
	int i = 0;
	int j = 0;

	while ((l1 <= mid) && (l2 <= high)) {
		if (order == 1) {
			if (arr_a[l1] < arr_a[l2]) {
				arr_b[i++] = arr_a[l1++];
			} else {
				arr_b[i++] = arr_a[l2++];
			}
		} else if (order == 2) {
			if (arr_a[l1] > arr_a[l2]) {
				arr_b[i++] = arr_a[l1++];
			} else {
				arr_b[i++] = arr_a[l2++];
			}
		}
	}

	while (l1 <= mid) {
		arr_b[i++] = arr_a[l1++];
	}

	while (l2 <= high) {
		arr_b[i++] = arr_a[l2++];
	}

	for (i = low, j = 0; i <= high; i++, j++ )
		arr_a[i] = arr_b[j];
}

void merge_sort(int arr[], int low, int high) {
	int mid;

	if (low < high) {
		mid = (low + high) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, (mid + 1), high);

		merge_arr(arr, low, mid, high);
	} else {
		return;
	}
}

int main (void) {
	int num;
	int i;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &num);

	printf("Enter the array elements:\n");
	for (i = 0; i < num; i++) {
		scanf("%d", &arr_a[i]);
	}

	printf("Enter the order of sorting:\n");
	printf("1. Ascending Order\n2. Descending order\n");
	scanf("%d", &order);

	if ((order ==1) || (order ==2)) {
		merge_sort(arr_a, 0, num);
	} else {
				printf("Invalid input!\n");
				exit(1);
	}
	
	printf("Array after sorting:\n");
	if (order == 1) {
		for (i = 1; i <= num; i++) {
			printf("%d\t", arr_a[i]);
		}
	} else if (order == 2) {
		for (i = 0; i < num; i++) {
			printf("%d\t", arr_a[i]);
		}
	}

	printf("\n");

	return 0;
}
