#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main (void) {
	int fd;
	pid_t pid;

	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the device\n");
	else
		printf("File opened successfully %d\n", fd);

	pid = vfork();

	ioctl(fd, getpid(), pid);

	close(fd);

	return 0;
}
