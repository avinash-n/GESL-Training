/* Header file for queue operations */

/* C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 5
#define MEM_ALLOC(str) str = (char *) malloc(LENGTH);
#define VALIDATE_MALLOC(str) if (!str) {\
				printf("Memory allocation failed!");\
				exit(0);\
				}

int my_atoi(char *);

int str_len(char *);

void (*fun_ptr)(int, int);

void add(int, int);

void sub(int, int);

void mul(int, int);

void _div(int, int);
