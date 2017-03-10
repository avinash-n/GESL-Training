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
	int s;
	int i;
	int p;	
	
	prio.sched_priority = 87;
	p = pthread_setschedparam(pthread_self(), SCHED_RR, &prio);
	if(p != 0)
		printf("pthraedj is failed\n");
	

	s = pthread_getschedparam(pthread_self(), &i, &prio);
	if(i == SCHED_RR)
		printf("child sched_rr\n");
	printf("child priority %d\n",prio.sched_priority);

	return NULL;
}

int main()
{
	int fd;
	pthread_t thr;
	pthread_t thr1;
	int p;
	int i;
	pthread_attr_t attr;

	printf("%d\n",getpid());
//	thr1 = pthread_self();
//	printf("aaa %d\n",thr1);

	fd = open("/dev/myChar",O_RDWR
	
	attrp = &attr;
	p = pthread_attr_init(&attr);
	
	if(p != 0)
		printf("hjpthraed is failed\n");


	p = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(p != 0)
		printf("pthrakhed is failed\n");

	
	p = pthread_create(&thr, &attr, thread_fun, NULL);
	if(p != 0)
		printf("pthraoued is failed\n");

	p = pthread_getschedparam(pthread_self(), &i, &prio);
	if(i == SCHED_OTHER)
		printf("parant sched_other\n");
	printf("parent priority %d\n",prio.sched_priority);
	
	pthread_exit(NULL);
	return 0;
}
