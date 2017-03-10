/*
 * Avinash N
 * 06/02/2017
*/

/*
 * Write two independent applications source and dest and make them communicate
 * using named pipe.
*/

// Destination program to read from the buffer

#include "errors.h"

int main (void) {
	int fd;				// File handler
	char *str = NULL;		// String variable to hold the message
	char *myfifo = "./myfifo";	// Path for named pipe

	if ((str = (char *) malloc (sizeof (char) * STR_LEN)) == NULL) 
		err_abort ("malloc() failed\n");

//	printf("Content of the buffer :\n");
//	printf("%s\n", str);

	fd = open (myfifo, O_RDONLY);
//	if (fd < 0) errno_abort (fd, "open() failed\n");

	read (fd, str, STR_LEN);

	printf("The received information id : %s\n", str);
//	printf("%s\n","global");

	close (fd);

	return 0;
}
