// Implimentation of quick sort algorithm

// User defined header file
#include "myheader.h"

#define NUM_LENGTH 5
#define MEM_ALLOC(str) str = (char *) malloc(sizeof(char) * NUM_LENGTH);
#define VALIDATE_MEM_ALLOC(str) if (!(str)) { \
					printf("Memory allocation failed!\n");\
					exit(1);\
					}
#define SWAP(num1, num2) num1 = num1 + num2;\
			    num2 = num1 - num2;\
			    num1 = num1 - num2;

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
				SWAP(arr[i], arr[j]);
			}
		}
		SWAP(arr[j], arr[pivot]);
		quick_sort(arr, low, j-1);
		quick_sort(arr, j+1, high);
	}
}

int main(void) {
	int arr[100];		// Array of numbers
	int num;		// Number of elements
	int i;
	int opt;		// Order of sorting
	char *temp;

	MEM_ALLOC(temp);
	VALIDATE_MEM_ALLOC(temp);

	printf("Enter the number of elements: ");
	fgets(temp, NUM_LENGTH, stdin);
	num = my_atoi(temp);
	free(temp);

	printf("Enter the elements:\n");
	for (i = 0; i < num; i++) {
		MEM_ALLOC(temp);
		VALIDATE_MEM_ALLOC(temp);
		fgets(temp, NUM_LENGTH, stdin); 
		arr[i] = my_atoi(temp);
		free(temp);
	}

	printf("Enter the order of sorting:\n");
	printf("1. Ascending order\n2. Descending order\n");
	scanf("%d", &opt);

	quick_sort(arr, 0, num);

	printf("Elements after sorting:\n");
	if (opt == 1) {
		for (i = 1; i <= num; i++) {
			printf("%d\t", arr[i]);
		}
	} else if (opt == 2) {
		for (i = num; i >= 1; i--) {
			printf("%d\t", arr[i]);
		}
	} else {
		printf("Invalid input!\n");
		exit(1);
	}
		
	printf("\n");

	return 0;
}
