/* Header file for Linked List functions */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_LENGTH 10			/* Maximum queue length */
#define NUM_SIZE 8				/* Maximum number of digits */
#define MEM_ALLOC(str) str = (char *) malloc(NUM_SIZE);
#define VALIDATE_MALLOC(str) if (!str) {\
				printf("Memory allocation failed!");\
				exit(0);\
				}

void insert_1(void);		/* Insert at the beginning */

void insert_2(void);		/* Insert at the end */

void insert_3(void);		/* Insert at agiven position */

void insert_4(void);		/* Insert before a given position */

void insert_5(void);		/* Insert after a given position */

void insert_6(void);		/* Insert before a given number */

void insert_7(void);		/* Insert after a given number */

void insert_8(void);		/* Insert at the middle */

void insert_9(void);		/* Insert at penultimate node */

int validate(char *);

int str_len(char *);

void disp(void);
