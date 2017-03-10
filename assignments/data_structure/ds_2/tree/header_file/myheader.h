// Header file for binary search tree program

// C header files
#include <stdio.h>
#include <stdlib.h>

// MACRO definitions
#define NUM_LENGTH 5
#define MEM_ALLOC(str) str = (char *) malloc(sizeof(char) * NUM_LENGTH)
#define VALIDATE_MEM_ALLOC(str) if (!(str)) {\
					printf("Memory allocation failed!\n");\
					exit(1);\
				}
#define MEM_ALLOC_S(str) str = (CHILD *) malloc(sizeof(CHILD))

// Structure definition for tree
typedef struct tree {
	int data;
	struct tree *l_child;
	struct tree *r_child;
}CHILD;
struct tree *root;

// Function declarations
int my_atoi(char *);
int str_len(char *);
void create_child(void);
void insert_child(CHILD *);
void display_tree(CHILD *);
void delete_node(void);
