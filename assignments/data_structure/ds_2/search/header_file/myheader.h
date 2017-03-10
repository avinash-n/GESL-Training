// Header file for searching algorithms

// C header files
#include <stdio.h>
#include <stdlib.h>

// Macro definitions
#define NUM_LENGTH 4	// Number of digits
#define MEM_ALLOC(str) str = (char *) malloc(NUM_LENGTH)
#define VALIDATE_MALLOC(str) if (!str) {\
				printf("Memory allocation failed!");\
				exit(1);\
				}

// Variable declaration
int number;		// Number of elements
int key;		// Element to be searched
int arr[100];		// Array of elements
enum algorithm {linear = 1, binary, leave = 0};

// Function Declaration
int my_atoi(char *);	// Convert fgets() input to integer
int str_len(char *);	// Find length of string
int linear_search(void);// Linear search algorithm
int binary_search(void);// Binary search algorithm
