#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

void *thread_fun(void *arg)
{
	int p;
	int s;
	int i;
	struct sched_param prio;
	pthread_attr_t gattr;
	pthread_t thr;
	pthread_attr_t attr;
	
	printf("before changing.....\n");
	getchar();

	s = pthread_getattr_np(pthread_self(), &gattr);
	
	s = pthread_getschedparam(pthread_self(), &i, &prio);
	if(i == SCHED_OTHER)
		printf("sched_rr\n");
	printf("priority %d\n",prio.sched_priority);

	p = pthread_attr_init(&attr);
	
	if(p != 0)
		printf("pthraed is failed\n");


	p = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(p != 0)
		printf("pthraed is failed\n");
	p = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(p != 0)
		printf("pthhed is failed\n");

	prio.sched_priority = 94;
	p = pthread_setschedparam(pthread_self(), SCHED_FIFO, &prio);
	if(p != 0)
		printf("pthread is failed\n");
	
	printf("after modifying the thread.....\n");
	getchar();
	s = pthread_getattr_np(pthread_self(), &gattr);

	p = pthread_attr_getdetachstate(&gattr, &i);
	if(p != 0)
		printf("pthhed hello is failed\n");
	if(i == PTHREAD_CREATE_JOINABLE)
		printf("hiii\n");
	s = pthread_getschedparam(pthread_self(), &i, &prio);
	if(i == SCHED_FIFO)
		printf("sched_fifo\n");
	printf("priority %d\n",prio.sched_priority);

	return NULL;
}

int main()
{
	pthread_t thr;
	int p;

	pthread_attr_t *attrp;
	p = pthread_create(&thr, NULL, thread_fun, NULL);
	if(p != 0)
		printf("pthraoued is failed\n");

	
	pthread_exit(NULL);
	return 0;
}
