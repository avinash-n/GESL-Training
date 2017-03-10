/*
 * Avinash N
 * 24 - 01 - 2017
*/

/*
 * Write a program to create a child process using vfork() system call and
 * experiment the following
 * a. Will both parent and child share the same local data ?
 * b. Will both parent and child share the same global data ?
 * c. Will both parent and child share the same heap data ?
 * d. Verify from the kernel space, whether both parent and child
 * 	will work in the separate/different instance of
 * 	the virtual address space or not ?
 * e. Open a text file “just.txt” in the parent before issuing fork().
 * 	* After issuing fork(), in the parent context, write the string
 * 		“Global Edge” on to the file and close the file.
 *	 * In the child context write “Software limited” on to the file
 * 		and close the file.
 *	 * Cat the file just.txt and draw your inferences
 * 		by looking at the output.
 * f. Verify from the kernel space, whether both parent and child
 * 	will share the same session descriptor or will they have 
 *	separate session descriptors ?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Memory allocation
#define MEM_ALLOC(ptr) ptr = (char *) malloc (sizeof(char))

// Malloc validation
#define VALIDATE(ptr) if (!ptr) {\
			printf("Malloc failed...!\n");\
			exit(1);\
			}

// Printing details of process
#define print_statements() \
	printf("PID --> %d\tPPID --> %d\n", getpid(), getppid()); \
	printf("Value of local variable = %d\n", l_num); \
	printf("Address of local variable = %p\n", &l_num); \
	printf("Value of global variable = %d\n", g_num); \
	printf("Address of global variable = %p\n", &g_num); \
	printf("Value of pointer variable = %s\n", ptr); \
	printf("Address of pointer variable = %p\n", ptr);

int g_num = 25;		// Global variable

int main (void) {
	int l_num = 10;		// Local variable
	char *ptr = NULL;	// Pointer to access heap data
	pid_t pid;
	FILE *fp;

	fp = fopen("just.txt", "w+");

	printf("-------------------------------------\n");
	printf("Value of local variable = %d\n", l_num); 
	printf("Value of global variable = %d\n", g_num); 

	pid = vfork();		// vfork() is invoked

//	wait(NULL);		// To make the parent process wait for child

	if (pid > 0) {
	MEM_ALLOC(ptr);		// Memory allocation for pointer
	VALIDATE(ptr);		// Malloc validation
	// Enter any character as input to ptr
	*ptr = getchar();

//		l_num = 100;
//		g_num = 200;
		fprintf(fp, "%s", "Global Edge\n");

		printf("----In parent process----\n");
		print_statements()
		printf("Exiting parent process\n");
	//	getchar();
		fclose(fp);
	} else if (pid == 0) {
	MEM_ALLOC(ptr);		// Memory allocation for pointer
	VALIDATE(ptr);		// Malloc validation
	// Enter any character as input to ptr
	*ptr = getchar();

		l_num = 50;
		g_num = 120;
		fprintf(fp, "%s", "Software Limited\n");

		printf("----In child process----\n");
		print_statements()
		printf("Exiting child process\n");
//		getchar();
		fclose(fp);
		exit(0);
	} else {
		printf("fork() failed..!\n");
	}

	printf("..Value of local variable = %d\n", l_num); 
	printf("..Value of global variable = %d\n", g_num); 

	return 0;
}

/*
 * Answer for a, b and c :
 *
 * Both parent and child share the same data(local, global and heap)
 * with same virtual adrress space (same instance)
 * mapped to seperate physical address spaces which when modified
 * in one process' context will affect the data in
 * the other process' context.
 *
 * Answer for d :
 *
 * Use "$ cat /proc/PID/maps" for both child and parent
 * -OR-
 * Use kernel module to traverse the linked list of vm_area_struct
 *
 * Answer for e :
 *
 * -------
 *
 * Answer for f :
 *
 * -------
*/ 
