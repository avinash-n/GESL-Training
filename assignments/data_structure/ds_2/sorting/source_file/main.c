/*
	Name: Sorting algorithms
	Author: Avinash N
	Description: This program illustrates the implementation of
			following sorting algorithms.
			1. Bubble sort
			2. Selection sort
			3. Insertion sort
			4. Merge sort
			5. Quick sort
*/

#include "sort.h"

int main(void) {
	char *temp = NULL;		// Variable to read on fgets
	int n_ele;		// Number of elements
	int order;		// Order of sorting
	int status;		// Status of successful execution of an algorithm

	MEM_ALLOC(temp);
	VALIDATE_MEM_ALLOC(temp);
	status = 1;

	fprintf(stdout, "%s", "----SORTING ALGORITHMS----\n");

	do {
		fprintf(stdout, "%s", "Enter the number of elements: ");	
		fgets(temp, DIGITS, stdin);

		n_ele = my_atoi(temp);

		do {
			if (n_ele > ARR_LENGTH) {
				fprintf(stdout, "%s", "Too many elements\n");
				break;
			} else {
				fprintf(stdout, "%s", "Enter the order of sorting:\n");
				fprintf(stdout, "%s", "1. Ascending order\n2. Descending order\n");
				fgets(temp, DIGITS, stdin);

				order = my_atoi(temp);
					
				if (!((order == 1) || (order ==2))) {
					fprintf(stdout, "%s", "Please enter the valid option\n");
				} else {
					do {
						fprintf(stdout, "%s", "Select the sorting algorithm:\n");
						fprintf(stdout, "%s", "1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Merge sort\n5. Quick sort\n");
						fprintf(stdout, "%s", "Press 0 to exit\n");
						fgets(temp, DIGITS, stdin);

						switch (my_atoi(temp)) {
						case 0:
							fprintf(stdout, "%s", "Program is terminated.\n");
							exit(0);
						case 1:							
							status = bubble(n_ele, order);
							break;
						case 2:
							status = selection(n_ele, order);
							break;
						case 3:
							status = insertion(n_ele, order);
							break;
						case 4:
							status = merge(n_ele, order);
							break;
						case 5:
							status = quick(n_ele, order);
							break;
						default:
							fprintf(stdout, "%s", "Please select the valid option\n");
						}
					} while (status);
					break;
				}
			}
		} while (1);
	} while (1);

	return 0;
}
