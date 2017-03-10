#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main (void) {
	int fd;
	unsigned int a;

	fd = open("/dev/myChar1", O_RDWR);

	if (fd < 0)
		perror("Unable to open the device\n");
	else
		printf("File opened successfully %d\n", fd);

	printf("PID in device file --> %d\n", getpid());

	scanf ("%x", &a);
	ioctl(fd, getpid(), a);
	getchar();

	close(fd);

	return 0;
}
