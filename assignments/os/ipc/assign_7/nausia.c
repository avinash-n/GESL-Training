/*
 * Avinash N
 * 07/02/2017
 */

/*
 * Re-write the assignment 6 without semaphores. First element of the array
 * will be the flag indicating the process to access the array.
 * If it is 1, then the process nausea will access the array if it is zero
 * then the process panacea will access.
 * Compile both the applications nausea and panacea with –O2 option.
*/

#include "errors.h"

int main (void) {
	int fd;
	int trunc;
	int *ptr;
	char buf[20];
	int i;

	if ((fd = shm_open ("/my_shm", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1)
		err_abort ("shm_open() failed\n");                                    

	if ((trunc = ftruncate (fd, sysconf (_SC_PAGE_SIZE))) == -1)
		errno_abort (trunc, "ftruncate() failed\n");

	ptr = (int *) mmap (NULL, sysconf (_SC_PAGE_SIZE), PROT_READ | PROT_WRITE,
					MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED)
		err_abort ("mmap() failed\n");                                    

//	if ((sem_open ("/my_sem", O_CREAT, 0666, 0)) == SEM_FAILED)
//		err_abort ("sem_open() failed\n");

	buf[0] = 1;

	do {
		for (i = 1; i < 11; i++)
			buf[i] = time (NULL) % (i);

		printf("Array elements before sharing :\n");
		for (i = 0; i < 11; i++)
			printf("Element - %d : %d\n", (i + 1), buf[i]);

		memcpy (ptr, buf, sizeof (buf));

		getchar();

		memcpy (buf, ptr, sizeof (buf));

		printf("Array elements after sharing :\n");
		for (i = 0; i < 11; i++)
			printf("Element - %d : %d\n", (i + 1), buf[i]);

		buf[0] = 0;
	} while (buf[0] == 1);

	munmap (NULL, sysconf(_SC_PAGE_SIZE));

	close (fd);

	return 0;
}
