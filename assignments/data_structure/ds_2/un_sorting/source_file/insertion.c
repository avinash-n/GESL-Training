// Bubble sorting algorithm

#include <stdio.h>
#include <stdlib.h>

#define XCHG arr[j + 1] = arr[j];\
	     arr[j] = min;

int main (void) {
	int arr[100];
	int num;
	int i;
	int j;
	int order;
	int min;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &num);

	printf("Enter the array elements:\n");
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter the order of sorting:\n");
	printf("1. Ascending Order\n2. Descending order\n");
	scanf("%d", &order);

	if ((order ==1) || (order ==2)) {
		for (i = 1; i < num; i++) {
			min = arr[i];
			for (j = (i - 1); j >= 0; j--) {
				if ((order == 1) && (arr[j] > min)) {
					XCHG;
				} else if ((order == 2) && (arr[j] < min)) {
					XCHG;
				} else {
						break;
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
