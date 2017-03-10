#include <stdio.h>
#include <fcntl.h>

int main (void) {
	int fd;

	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the device\n");
	else
		printf("File opened successfully %d\n", fd);

//	printf("PID in device file --> %d\n", getpid());
	ioctl(fd, getpid(), 10);

	close(fd);

	return 0;
}
