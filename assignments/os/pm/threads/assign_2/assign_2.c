/*
 * Avinash N
 * 27/01/2017
*/

/* Write a program to do the following
 * a. Process creating a process
 * b. Process creating a thread
 * c. Thread creating a process
 * d. Thread creating a thread
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>

void *thread_function2 (void *p2) {
	getchar();
	printf("In thread function - 2\n");
	printf("PID --> %d\t TID --> %ld\n", getpid(), syscall(SYS_gettid));


	return NULL;
}

// Invert the commented lines to perform c
void *thread_function1 (void *p1) {
	int thread_status;
	pthread_t thread_th_id;
//	pid_t pid;

	thread_status = pthread_create (&thread_th_id, NULL, thread_function2, NULL);
	if (thread_status != 0) {
		printf("Thread creation failed: %s", strerror(thread_status));
	}

	getchar();

	printf("In thread function - 1\n");
	printf("PID --> %d\t TID --> %ld\n", getpid(), syscall(SYS_gettid));

	pthread_exit (NULL);

/*	pid = fork();
	wait(NULL);
	if (pid > 0) {
		printf("I am parent process in thread function\n");
		getchar();
	} else if (pid == 0) {
		printf("I am child process in thread function\n");
	} else {
		printf("fork() in thread failed\n");
	}
*/
	return NULL;
}

int main (void) {
	int status;
	pthread_t th_id;

	status = pthread_create (&th_id, NULL, thread_function1, NULL);
	if (status != 0) {
		printf("Thread creation failed: %s", strerror(status));
	}

	getchar();

	printf("I am in main function\n");
	printf("PID --> %d\t TID --> %ld\n", getpid(), syscall(SYS_gettid));

	pthread_exit (NULL);

	return 0;
}
