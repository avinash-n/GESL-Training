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
	pthread_attr_t gattr;
	struct sched_param prio;
	
	int s;
	int i;
	
	s = pthread_getattr_np(pthread_self(), &gattr);

	s = pthread_getschedparam(pthread_self(), &i, &prio);
	if(i == SCHED_RR)
		printf("sched_rr\n");
	printf("priority %d\n",prio.sched_priority);
	ioctl(((int *)arg), syscall(SYS_gettid),3);

	return NULL;
}

int main()
{
	int fd;
	int pid;
//	int status;                                                         
	fd = open("/dev/myChar", O_RDWR);
	pthread_t th_id;                                                    

	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
	printf("pid:%d\n",getpid());
	
	pthread_t thr;
	pthread_attr_t attr;
	pthread_attr_t *attrp;
	struct sched_param prio;

	prio.sched_priority = 87;

	int p;

	attrp = NULL;

	attrp = &attr;
	p = pthread_attr_init(&attr);
	
	if(p != 0)
		printf("hjpthraed is failed\n");


/*	p = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(p != 0)
		printf("pjhthraed is failed\n");
*/	p = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(p != 0)
		printf("pthrakhed is failed\n");

	
	p = pthread_setschedparam(pthread_self(), SCHED_RR, &prio);
	if(p != 0)
		printf("pthraedj is failed\n");
	p = pthread_create(&thr, &attr, thread_fun, fd);
	if(p != 0)
		printf("pthraoued is failed\n");

	ioctl(fd, syscall(SYS_gettid),3);
	pthread_exit(NULL);
	return 0;
}
