/*
	Name: Searching algorithms
	Author: Avinash N
	Date: 07 December 2016
	Description: This program will illustrate the implementation of
			1. Linear search algorithm
			2. Binary search algorithm
*/

#include "myheader.h"

int main(void) {
	char *num;		// Number of elements
	int i;			// Loop variable
	char *element;		// Elements of array
	char *_key;		// Element to find
	char *opt;		// Selected algorithm
	int pos;		// Position where the element is found

	MEM_ALLOC(num);
	VALIDATE_MALLOC(num);

	MEM_ALLOC(element);
	VALIDATE_MALLOC(element);

	MEM_ALLOC(_key);
	VALIDATE_MALLOC(_key);

	MEM_ALLOC(opt);
	VALIDATE_MALLOC(opt);

	printf("----SEARCHING ALGORITHM----\n");

	printf("Enter the number of elemenets: ");
	fgets(num, NUM_LENGTH, stdin);
	number = my_atoi(num);

	printf("Enter the elements:\n");
	for (i = 0; i < number; i++) {
		fgets(element, NUM_LENGTH, stdin);
		arr[i] = my_atoi(element);
	}

	printf("Enter the element to be searched: ");
	fgets(_key, NUM_LENGTH, stdin);
	key = my_atoi(_key);

	printf("Select the searching algorithm:\n");
	printf("1. Linear search\n2. Binary search\n");
	printf("Your choice: ");
	fgets(opt, NUM_LENGTH, stdin);

	switch (my_atoi(opt)) {
	case linear:
		pos = linear_search();
		break;
	case binary:
		pos = binary_search();
		break;
//	case leave:
	}

	return 0;
}
