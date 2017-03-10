/* Header file for file operations */

/* C header files */
#include <stdio.h>
#include <stdlib.h>

/* Validation of parameters */
#define VALIDATE_ARGC if (argc != 2) {\
				printf("Too many files!\n");\
				exit(1);\
			}

#define VALIDATE_FP if (!(fp)) {\
				printf("File operation failed!\n");\
				exit(1);\
			}

/* File handler to read the file 
FILE *fp;
*/
/* Function declarations */
int wrd_cnt();
