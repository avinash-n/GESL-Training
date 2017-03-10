// Selection sorting algorithm

#include <stdio.h>
#include <stdlib.h>

#define SWAP arr[i] = arr[i] + arr[min];\
	     arr[min] = arr[i] - arr[min];\
	     arr[i] = arr[i] - arr[min];

int main (void) {
	int arr[100];
	int num;
	int min;
	int i;
	int j;
	int order;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &num);

	printf("Enter the array elements:\n");
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter the order of sorting:\n");
	printf("1. Ascending order\n2. Descending order\n");
	scanf("%d", &order);

	if ((order == 1) || (order == 2)) {
		for (i = 0; i < (num - 1); i++) {
			min = i;
			for (j = (i + 1); j < (num); j++) {
				if ((order == 1) && (arr[min] > arr[j])) {
					min = j;
				}
				if ((order == 2) && (arr[min] < arr[j])) {
					min = j;
				}
			}
			if (arr[min] != arr[i]) {
				SWAP;
			}
		}
	} else {
		printf("Invalid input!\n");
		exit(1);
	}

	printf("Array after sorting:\n");
	for (i = 0; i < num; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");

	return 0;
}
