/*
 * Avinash N
 * 28/01/2017
*/

/*
 * Alarm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void *th_alarm(void *time) {
	int i;
	printf("I am in thread function\n");
	sleep(*((int *)time));
	printf("Alarm beeping\n");
	//for (i = 0;; i++)
		printf("\a");

	return NULL;
}

int main (void) {
	int status;
	int time_sec = 5;
//	char *message = NULL;
	pthread_t th_id;

//	do {
		status = pthread_create (&th_id, NULL, th_alarm, &time_sec);
		if (status !=0 ) {
			printf("Thrtead creation failed: %s\n", strerror(status));
		}

	pthread_exit(NULL);

	return 0;
}
