/*
 * Avinash N
 * 01/02/2017
*/

/*
 * Assignment 6
*/

#include "errors.h"

typedef struct th_alarm1 {
	pthread_mutex_t mutex;
	int sec;			// Variable to hold time
	char msg[128];		// Array to hold message of alarm
	struct th_alarm1 *next;	// Pointer to next node
}th_alarm_t;

th_alarm_t *head = NULL;
th_alarm_t *th_alarm = NULL;

void *th_alarm_thread (void *arg) {
	int th_status;		// To monitor return value of function

//	if(NULL == (th_alarm = ((th_alarm_t *)malloc(sizeof(th_alarm_t)))))		
//		errno_abort("malloc() failed\n");

	while(1) {
		if(head == NULL){
			sleep(1);
			continue;	
		} else {
			th_status = pthread_mutex_lock (&th_alarm -> mutex);
			if(th_status != 0) 
				err_abort(th_status, "pthread_mutex_lock() failed\n");
			else {
				th_alarm = head;
			}
				
			th_status = pthread_mutex_unlock (&th_alarm -> mutex);
			if(th_status != 0) 
				err_abort(th_status, "pthread_mutex_unlock() failed\n");

			sleep(th_alarm -> sec);
			printf("(%d) %s\n", th_alarm -> sec, th_alarm -> msg);

			head = th_alarm -> next;
			free(th_alarm);
			
		}
	}
	return NULL;
}

int main (void) {
	char line[128];		// Variable to take input from the user
	int status;			// To monitor the return value of functions
	pthread_t th_id;	// Thread instance
//	head = NULL;
//	th_alarm = NULL;

	status = pthread_create(&th_id, NULL, th_alarm_thread, NULL);
	if(status != 0)
		err_abort(status, "pthread_create() failed\n");

//	signal (SIGCHLD, SIG_IGN);

	while(1) {
		printf("Alarm : ");
		if (fgets(line, sizeof(line), stdin) == NULL) exit(1);
		if (strlen(line) <= 1) continue;

		if (NULL == (th_alarm = ((th_alarm_t *)malloc(sizeof(th_alarm_t)))))
			errno_abort("malloc() failed\n");

		if(sscanf(line, "%d %64[^\n]",&th_alarm -> sec, th_alarm -> msg) > 2) {
			fprintf(stderr, "Bad command");
			continue;
		} 

		status = pthread_mutex_init (&th_alarm -> mutex, NULL);
		if(status != 0) 
			err_abort(status, "pthread_mutex_init() failed\n");

		status = pthread_mutex_lock (&th_alarm -> mutex);
		if(status != 0) 
			err_abort(status, "pthread_mutex_lock() failed\n");
		
//		printf("%d %s\n", th_alarm -> sec, th_alarm -> msg);

		if (head == NULL) {
			th_alarm -> next = NULL;
			head = th_alarm;
		} else {
			th_alarm -> next = head;
			head = th_alarm;
		}

		status = pthread_mutex_unlock (&th_alarm -> mutex);
		if(status != 0) 
			err_abort(status, "pthread_mutex_unlock() failed\n");
	}

	pthread_exit(NULL);
	return 0;
}
