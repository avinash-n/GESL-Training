/*
 * Avinash N
 * 06/02/2017
*/

/*
 * Write two independent applications source and dest and make them communicate
 * using named pipe.
*/

// Source program to write into the buffer

#include "errors.h"

int main (void) {
	int fd;						// File handler
	char *myfifo = "./myfifo";	// Path for named pipe
	char *str = "Global_edge";	// String variable to hold the message
//	int status;					// To track the return value of function call

	mkfifo (myfifo, 0666);
//	if (status != 0) errno_abort (status, "mkfifo() failed\n");

	fd = open (myfifo, O_WRONLY);
//	if (fd < 0) errno_abort (fd, "open() failed\n");

//	printf ("Enter the string :\n");
//	fgets (str, STR_LEN, stdin);

	write (fd, str, STR_LEN);

	close (fd);

	unlink (myfifo);

	return 0;
}
