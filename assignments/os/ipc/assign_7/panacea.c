/*
 * Avinash N
 * 07/02/2017
 */

/*
 * Write two independent applications nausea and panacea which will work on
 * the data available on the shared memory. nausea will initially write
 * an array of 10 integers whose values are (time() mod array index)
 * onto shared memory and panacea will read all the elements and print
 * and re-initialize all the array elements to zero. Both nausea and panacea
 * will synchronize the access to the shared memory using POSIX semaphores.
 */

#include "errors.h"

int main (void) {
	int fd;
	int *ptr;
	char buf[20];
	int i;

	if ((fd = shm_open ("/my_shm", O_RDWR, 0666)) == -1)
		err_abort ("shm_open() failed\n");

	ptr = (int *) mmap (NULL, sysconf(_SC_PAGE_SIZE), PROT_READ | PROT_WRITE,
						MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED)
		err_abort ("mmap() failed\n");

//	if ((sem_open ("/my_sem", O_CREAT, 0666, 0)) == SEM_FAILED)
//		err_abort ("sem_open() failed\n");

	do {
		memcpy (buf, ptr, sizeof (buf));

		printf("Array elements before modifying :\n");
		for (i = 0; i < 11; i++)
			printf("Element - %d : %d\n", (i + 1), buf[i]);

		memset (ptr, 0, sizeof (buf));
		memcpy (buf, ptr, sizeof (buf));

		printf("Array elements after modifying :\n");
		for (i = 0; i < 11; i++)
			printf("time = %d\n", buf[i]);

		buf[0] = 1;
	} while (buf[0] == 0);

		munmap (NULL, sysconf(_SC_PAGE_SIZE));

	close (fd);

	return 0;
}
