#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

void *thread_function (void *fd) {
        printf("I am in thread function\n");
        printf("TGID --> %d\n", getpid());
        printf("PID --> %ld\n", syscall(SYS_gettid));

	ioctl(*((int *)fd), syscall(SYS_gettid), 0000);

        return NULL;
}

int main (void) {
	int fd;
	int status;
	pthread_t th_id;

	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the device\n");
	else
		printf("File opened successfully %d\n", fd);

	status = pthread_create (&th_id, NULL, thread_function, &fd);
	if (status != 0) {
		printf("Thread creation failed: %s", strerror(status));
	}

	getchar();

	printf("I am in main function\n");
        printf("TGID --> %d\n", getpid());
        printf("PID --> %ld\n", syscall(SYS_gettid));
	ioctl(fd, syscall(SYS_gettid), 0000);

	pthread_exit (NULL);

	close(fd);

	return 0;
}
