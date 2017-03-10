/*
 * Avinash N
 * 30/01/2017
*/

/*
 * Assignment 5
*/

#include "errors.h"

typedef struct t_alarm {
	int sec;
	char msg[100];
	struct t_alarm *next;
}alarm_t;

void *alarm_thread (void *arg) {
	alarm_t *th_alarm = NULL;
	th_alarm = (alarm_t *)arg;

	sleep (th_alarm -> sec);
	printf("(%d) %s\n",th_alarm -> sec, th_alarm -> msg);
	
	free(th_alarm);
	th_alarm = NULL;

	return NULL;
}

int main (void) {
	char line[120];
	int status;
	alarm_t *alarm = NULL;
	alarm_t *head = NULL;
	pthread_t th_id;
	
	while(1) {
		if ((alarm = (alarm_t *) malloc (sizeof (alarm_t))) == NULL)
			errno_abort("malloc() failed\n");
		if(head == NULL) {
			head = alarm;
			alarm->next = NULL;
		}
		else {
			alarm->next = head;
			head = alarm;
		}

		printf("Alarm : ");
		if (fgets(line, sizeof(line), stdin) == NULL) exit(0);
		if (strlen (line) <= 1) continue;

		if (sscanf(line, "%d %64[^\n]",&alarm->sec, alarm->msg) > 2)
			fprintf(stderr,"Bad command");
		else {
			status = pthread_create(&th_id, NULL, alarm_thread, head);
			if(status != 0)
				err_abort(status, "pthread_create failed");
		}

	}
	pthread_exit(NULL);
	return 0;
}
