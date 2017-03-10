#define _GNU_SOURCE
#include "errors.h"

void *thread_fun (void *arg) {
	int policy;
	int th_status;	
	struct sched_param th_prio;
	
	th_status = pthread_getschedparam(pthread_self(), &policy, &th_prio);
	if(th_status != 0)
		err_abort(th_status ,"pthread_getschedparam");

	if(policy == SCHED_RR)
		printf("Child thread's scheduling policy : SCHED_RR\n");
	else if(policy == SCHED_FIFO)
		printf("Child thread's scheduling policy : SCHED_FIFO\n");
	else if(policy == SCHED_OTHER)
		printf("Child thread's scheduling policy : SCHED_OTHER\n");

	printf("Child thread's priority : %d\n",th_prio.sched_priority);

	return NULL;
}

int main (void) {
	int status;
	pthread_t th_id;
	pthread_attr_t attr;
	struct sched_param prio;

	status = pthread_attr_init(&attr);
	if(status != 0)
		err_abort(status, "pthread_attr_init");

	status = pthread_attr_setschedpolicy(&attr, SCHED_RR);
	if(status != 0)
		err_abort(status, "pthread_setschedpolicy");

	prio.sched_priority = 68;
	status = pthread_attr_setschedparam(&attr, &prio);
	if(status != 0)
		err_abort(status, "pthread_setschedparam");

	status = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(status != 0)
		err_abort(status, "pthread_attr_setinheritsched");

	status = pthread_create(&th_id, &attr, thread_fun, NULL);
	if(status != 0)
		err_abort(status ,"pthread_create is failed\n");

	pthread_exit(NULL);
	return 0;
}
