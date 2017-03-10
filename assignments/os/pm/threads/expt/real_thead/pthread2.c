#define _GNU_SOURCE
#include "errors.h"

void *thread_fun(void *arg)
{
	int i;
	int p;	
	struct sched_param prio;
	pthread_attr_t attr;

	prio.sched_priority = 68;

	p = pthread_attr_init(&attr);
	if(p != 0)
		err_abort(p, "pthread_attr_init");
	
	p = pthread_setschedparam(pthread_self(), SCHED_FIFO, &prio);
	if(p != 0)
		err_abort(p, "pthread_setschedparam");
	
	p = pthread_getschedparam(pthread_self(), &i, &prio);
	if(p != 0)
		err_abort(p ,"pthread_getschedparam");

	if(i == SCHED_RR)
		printf("child sched_rr\n");
	else if(i == SCHED_FIFO)
		printf("child sched_fifo\n");
	else if(i == SCHED_OTHER)
		printf("child sched_other\n");

	printf("child priority %d\n",prio.sched_priority);

	return NULL;
}

int main()
{
	int p;
	int i;
	pthread_t thr;
	

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
	p = pthread_create(&thr, NULL, thread_fun, NULL);
	if(p != 0)
		err_abort(p ,"pthread_create is failed\n");

	pthread_exit(NULL);
	return 0;
}
