/*
 * Avinash N
 * 27/01/2017
*/

/*
 * Write a program to create a thread and print pid of both thread group
 * leader and the thread using getpid() in the respective contexts.
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

void *thread_function (void *p) {
	printf("I am in thread function\n");
	printf("TGID --> %d\n", getpid());
	printf("PID --> %ld\n", syscall(SYS_gettid));

	getchar();

	return NULL;
}

int main (void) {
	int status;
	pthread_t th_id;

	status = pthread_create (&th_id, NULL, thread_function, NULL);
	if (status != 0) {
		printf("Thread creation failed: %s", strerror(status));
	}

	getchar();

	printf("I am in main function\n");
	printf("PID --> %d\n", getpid());
	printf("PID --> %ld\n", syscall(SYS_gettid));

	status = pthread_create (&th_id, NULL, thread_function, NULL);
	if (status != 0) {
		printf("Thread creation failed: %s", strerror(status));
	}
	getchar();

	printf("I am in main function\n");
	printf("PID --> %d\n", getpid());
	printf("PID --> %ld\n", syscall(SYS_gettid));
	pthread_exit (NULL);

	return 0;
}
