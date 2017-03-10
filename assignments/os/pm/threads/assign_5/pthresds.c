#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

void *thread_fun(void *arg)
{
	pthread_attr_t gattr;
	struct sched_param prio;
	
	int th_status;
	int i;
	
	th_status = pthread_getattr_np(pthread_self(), &gattr);

	th_status = pthread_getschedparam(pthread_self(), &i, &prio);
	if(i == SCHED_RR)
		printf("sched_rr\n");
	printf("priority %d\n",prio.sched_priority);

	return NULL;
}

int main()
{
	pthread_t th;
	pthread_attr_t attr;
	pthread_attr_t *attrp = NULL;
	struct sched_param prio;
	int status;

	prio.sched_priority = 87;
	attrp = &attr;
	status = pthread_attr_init(&attr);
	
	if(status != 0)
		printf("hjpthraed is failed\n");

	status = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(status != 0)
		printf("pjhthraed is failed\n");

	status = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(status != 0)
		printf("pthrakhed is failed\n");

	
	status = pthread_setschedparam(pthread_self(), SCHED_RR, &prio);
	if(status != 0)
		printf("pthraedj is failed\n");

	status = pthread_create(&th, &attr, thread_fun, &status);
	if(status != 0)
		printf("pthraoued is failed\n");

	
	pthread_exit(NULL);
	return 0;
}
