#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>

int a = 100;

int main (void) {
	int fd;
	char *ptr = NULL;

        fd = open("/dev/myChar", O_RDWR);

        if (fd < 0)
                perror("Unable to open the device\n");
        else
                printf("File opened successfully %d\n", fd);

	ptr = (char *) malloc (sizeof (char));

	strcpy (ptr, "Hello");

//      printf("PID in device file --> %d\n", getpid());
    ioctl(fd, getpid(), 0);

    close(fd);

	return 0;
}
