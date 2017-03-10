#include<stdio.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/syscall.h>
#include<unistd.h>

void *hello(void *p)
{

	printf("thread \n");
	ioctl(*((int *)p), syscall(SYS_gettid), 10);
	
	return NULL;
}

int main()
{
	pthread_t tid;
	int fd;
	int err;
	printf("%d\n",getpid());

	fd = open("/dev/myChar",O_RDWR);

	if(fd < 0)
		perror("unable to open the device ");
	else
		printf("File opened successfully %d\n",fd);

	
	err = pthread_create(&tid, NULL, hello, &fd);
	if(err != 0)
		printf("can't create thread : %d", strerror(err));
	else
		printf("Thread created suceessfully \n");
	
	ioctl(fd, syscall(SYS_gettid), 10);
	getchar();

	close(fd);
	pthread_exit(NULL);	


	return 0;
}
