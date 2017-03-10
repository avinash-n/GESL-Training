/*
 * Avinash N
 * 27/01/2017
*/

/*
 * Question 3
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define STR_LEN 32
#define MEM(ptr) ptr = (char *) malloc (sizeof(char) * STR_LEN)
#define VAL(ptr) if (!ptr) {\
			printf("Failed!\n");\
			exit(1);\
			}

int g_num = 100;		// Global data

void *thread_function (void *str) {
	g_num = g_num + 43;
	int tl_num = 21;		// Local data
	printf("I am in thread function\n");
	printf("TGID --> %d\n", getpid());
	printf("PID --> %ld\n", syscall(SYS_gettid));
	printf("Value of global variable --> %d\n", g_num);
//	printf("Value of pointer --> %s\n", (char *)str);
//	printf("Value of local variable --> %d\n", *((int *)str));
//	printf("Address of local variable --> %p\n", (int *)str);
	printf("Value of local variable --> %d\n", tl_num);
	printf("Address of local variable --> %p\n", &tl_num);

	getchar();

	return NULL;
}

int main (void) {
	int status;
	pthread_t th_id;

	char *ptr = NULL;	// Heap data
	MEM(ptr);
	VAL(ptr);
	strcpy(ptr, "Global_Edge");

	int l_num = 21;		// Local data

	status = pthread_create (&th_id, NULL, thread_function, &l_num);//&l_num
	if (status != 0) {
		printf("Thread creation failed: %s", strerror(status));
	}

	//getchar();

	printf("I am in main function\n");
	printf("PID --> %d\n", getpid());
	printf("PID --> %ld\n", syscall(SYS_gettid));
	printf("Value of global variable --> %d\n", g_num);
	printf("Value of pointer --> %s\n", ptr);
	printf("Value of local variable --> %d\n", l_num);
	printf("Address of local variable --> %p\n", &l_num);

	getchar();
	pthread_exit (NULL);

	return 0;
}

/*
 * a. Global data is shared between TGL and thread.
 * b. Heap data is shared between TGL and thread.
 * c. Stach segment is not shared between TGL and thread.
*/
