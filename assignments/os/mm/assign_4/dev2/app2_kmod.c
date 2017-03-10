#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main (void) {
	int fd;
	unsigned int a;

	fd = open("/dev/myChar2", O_RDWR);

	if (fd < 0)
		perror("Unable to open the device\n");
	else
		printf("File opened successfully %d\n", fd);

	printf("PID in device file --> %d\n", getpid());
	fscanf (stdin, "%d", &a);

	getchar();

	ioctl(fd, getpid(), a);

	close(fd);

	return 0;
}
