#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include <fcntl.h>

void *thread_fun(void *arg)
{
	pthread_attr_t attr;
	struct sched_param prio;
	int status;
	int policy;
	
	prio.sched_priority = 60;

	status = pthread_attr_init(&attr);
	if(status != 0)
		printf("pthread_attr_init() failed\n");

	status = pthread_setschedparam(pthread_self(), SCHED_RR, &prio);
	if(status != 0)
		printf("pthread_setschedparam() failed\n");

	status = pthread_getschedparam(pthread_self(), &policy, &prio);
	if(status != 0)
		printf("pthread_getschedparam() failed\n");
/*
	status = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(status != 0)
		printf("pthread_attr_setdetachstate() failed\n");

	status = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(status != 0)
		printf("pthread_attr_setinheritsched() failed\n");

	status = pthread_getattr_np(pthread_self(), &attr);
	if(status != 0)
		printf("pthread_getattr_np() failed\n");
*/
	printf ("Scheduling policy no. --> %d\n", policy);
	if(policy == SCHED_RR)
		printf ("Scheduling policy name --> %s\n", "SCHED_FIFO");

	printf("priority %d\n",prio.sched_priority);
	ioctl((int *)arg, syscall(SYS_gettid), 0000);

	return NULL;
}

int main (void) {
	int fd;
	int pid;
	int status;                                                         
	pthread_t th_id;                                                    


	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
	
/*
	status = pthread_attr_init(&attr);
	if(status != 0)
		printf("pthread_attr_init() failed\n");

	status = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(status != 0)
		printf("pthread_attr_setdetachstate() failed\n");

	status = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(status != 0)
		printf("pthread_attr_setinheritsched() failed\n");

	status = pthread_setschedparam(pthread_self(), SCHED_RR, &prio);
	if(status != 0)
		printf("pthread_setschedparam() failed\n");
*/
	status = pthread_create(&th_id, NULL, thread_fun, fd);
	if(status != 0)
		printf("pthread_create() failed\n");


	pthread_exit(NULL);

	return 0;
}
