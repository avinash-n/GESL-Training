#define _GNU_SOURCE
#include "errors.h"

void *thread_fun (void *arg) {
	int policy;
	int th_status;	
	struct sched_param prio;
	pthread_attr_t attr;

	prio.sched_priority = 86;

	th_status = pthread_attr_init(&attr);
	if(th_status != 0)
		err_abort(th_status, "pthread_attr_init");
	
	th_status = pthread_setschedparam(pthread_self(), SCHED_FIFO, &prio);
	if(th_status != 0)
		err_abort(th_status, "pthread_setschedparam");
	
	th_status = pthread_getschedparam(pthread_self(), &policy, &prio);
	if(th_status != 0)
		err_abort(th_status ,"pthread_getschedparam");

	if(policy == SCHED_RR)
		printf("Child thread's scheduling policy : SCHED_RR\n");
	else if(policy == SCHED_FIFO)
		printf("Child thread's scheduling policy : SCHED_FIFO\n");
	else if(policy == SCHED_OTHER)
		printf("Child thread's scheduling policy : SCHED_OTHER\n");

	printf("Child thread's priority : %d\n",prio.sched_priority);

	return NULL;
}

int main (void) {
	int status;
	pthread_t th_id;

/*	p = pthread_attr_init(&attr);
	if(p != 0)
		err_abort(p, "pthread_attr_init");

	p = pthread_attr_setschedpolicy(&attr, SCHED_RR);
	if(p != 0)
		errno_abort("pthread_setschedpolicy");

	prio.sched_priority = 87;
	p = pthread_attr_setschedparam(&attr, &prio);
	if(p != 0)
		err_abort(p, "pthread_setschedparam");


	p = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(p != 0)
		err_abort(p, "pthread_attr_setinheritsched");
*/
	status = pthread_create(&th_id, NULL, thread_fun, NULL);
	if(status != 0)
		err_abort(status ,"pthread_create is failed\n");

	pthread_exit(NULL);
	return 0;
}
