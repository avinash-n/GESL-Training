// Bubble sorting algorithm

#include <stdio.h>
#include <stdlib.h>

#define SWAP arr[j] = arr[j] + arr[j + 1];\
			 arr[j + 1] = arr[j] - arr[j + 1];\
			 arr[j] = arr[j] - arr[j + 1];

int main (void) {
	int arr[100];
	int num;
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
	printf("1. Ascending Order\n2. Descending order\n");
	scanf("%d", &order);

	if ((order == 1) || (order == 2)) {
		for (i = 0; i < (num - 1); i++) {
			for (j = 0; j < (num - i - 1); j++) {
				if ((order == 1) && (arr[j] > arr[j + 1])) {
					SWAP;
				} else if ((order == 2) && (arr[j] < arr[j + 1])) {
					SWAP;
				}
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
