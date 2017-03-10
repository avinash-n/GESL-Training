// User defined header file for sorting algorithm

// C header files
#include <stdio.h>
#include <stdlib.h>

// MACRO definitions
#define DIGITS 5

#define MEM_ALLOC(str) str = (char *) malloc (sizeof(char) * DIGITS);

#define VALIDATE_MEM_ALLOC(str) if (!(str)) {\
					printf("Memory allocation failed!\n");\
					exit(1);\
				}

#define SWAP arr[j] = arr[j] + arr[j + 1];\
	     arr[j + 1] = arr[j] - arr[j + 1];\
	     arr[j] = arr[j] - arr[j + 1];

#define READ_ARRAY fprintf(stdout, "%s", "Enter the elements:\n");\
		   for (i = 0; i < num_ele; i++) {\
			fgets(temp, DIGITS, stdin);\
			arr[i] = my_atoi(temp);\
		   }

#define PRINT_ARRAY fprintf(stdout, "%s", "Array after sorting:\n");\
		    for (i = 0; i < num_ele; i++)\
			fprintf(stdout, "%d", arr[i]);

// Variable declarations
int arr[ARR_LENGTH];		// Array of elements

//Function declarations
int my_atoi(char *);		// ASCII to integer conversion
int str_len(char *);		// String length calculation
int bubble(int , int );
int selection(int , int );
int insertion(int , int );
int merge(int , int );
int quick(int , int );
