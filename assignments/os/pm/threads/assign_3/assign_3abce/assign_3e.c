/*
 * Avinash N
 * 27/01/2017
*/

/*
 * Question 3.e
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

void *thread_function (void *fp) {
	fprintf(fp, "%s", "Software limited ");
	fclose(fp);

	printf("I am in thread function\n");
	printf("TGID --> %d\n", getpid());
	printf("PID --> %ld\n", syscall(SYS_gettid));

	getchar();

	return NULL;
}

int main (void) {
	int status;
	pthread_t th_id;
	FILE *fp;

	fp = fopen ("just.txt", "w+");

	status = pthread_create (&th_id, NULL, thread_function, fp);
	if (status != 0) {
		printf("Thread creation failed: %s", strerror(status));
	}

	fprintf(fp, "%s", "Global Edge ");
	fclose(fp);

	getchar();

	printf("I am in main function\n");
	printf("PID --> %d\n", getpid());
	printf("PID --> %ld\n", syscall(SYS_gettid));

	pthread_exit (NULL);

	return 0;
}

/*
 * INFERENCE :
 * 	Once the file handler is closed(un-engaged), file can not be accessed,
 * because both TGL and thread have a single file descriptor.
*/
