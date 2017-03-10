#include "errors.h"

typedef struct alarm {
	int sec;
	char mesg[100];
	struct alarm *next;
	
}alarm_t;

void *alarm_thread(void *arg) 
{
	alarm_t *alarm = NULL;

	alarm = (alarm_t *)arg;

	sleep (alarm->sec);
	printf("(%d) %s \n",alarm->sec, alarm->mesg);
	
	free(alarm);

	return NULL;
}

int main(int argc, char *argv[])
{
	char line[120];
	int p;
	pid_t pid;
	alarm_t *alarm = NULL;
	alarm_t *head = NULL;
	pthread_t thr;
		
	signal(SIGCHLD, SIG_IGN);
	
	while(1) {
		if(NULL == (alarm = ((alarm_t *)malloc(sizeof(alarm_t)))))		
			errno_abort("malloc is failed");
		if(head == NULL) {
			head = alarm;
			alarm->next = NULL;
		}
		else {
			alarm->next = head;
			head = alarm;
		}

		printf("Alaram ");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);
		if(strlen (line) <= 1) 
			continue;

		if(sscanf(line, "%d %64[^\n]",&alarm->sec, alarm->mesg) > 2) {
			fprintf(stderr,"Bad command");
		} 
		else {
			p = pthread_create(&thr, NULL, alarm_thread, head);
			if(p != 0)
				err_abort(p, "pthread_create failed");
		}

	}
	pthread_exit(NULL);
	return 0;
}


