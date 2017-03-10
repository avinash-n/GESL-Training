// Linear search

#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int arr[100];
	int num;
	int key;
	int i;

	printf("Enter the number of elements in array: ");
	scanf("%d", &num);

	printf("Enter the elements of the array:\n");
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter the key to search: ");
	scanf("%d", &key);

	for (i = 0; (i < num); i++) {
		if (arr[i] == key) {
			break;
		}
	}

	printf("%d is found at position %d", key, i);

	return 0;
}
