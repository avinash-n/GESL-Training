/* Header file for file operations */

/* C header files */
#include <stdio.h>
#include <stdlib.h>

/* Validation of parameters */
#define VALIDATE_ARGC if (argc != 3) {\
				printf("Too many files!\n");\
				exit(1);\
			}

#define VALIDATE_FP(fp) if (!(fp)) {\
				printf("File operation failed!\n");\
				exit(1);\
			}
