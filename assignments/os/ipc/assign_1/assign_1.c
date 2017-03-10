/*
 * Avinash N
 * 06/02/2017
*/

/*
 * Write a program which will create a child process and make the parent
 * and child communicate using unnamed pipe.
*/

#include "errors.h"

int main (void) {
	pid_t pid;
	char parent_buf;
	char child_buf;
	int pipefd[2];

	if (pipe(pipefd) == -1) errno_abort(-1, "pipe() failed\n");

	pid = fork();

	if (pid > 0) {
		close (pipefd[0]);	// Close the read end of parent

	//	printf ("In parent process :\n");
	//	printf ("Enter the input to send to child via pipe :\n");

		while ((parent_buf = getchar()) != 27)
			write (pipefd[1], &parent_buf, 1);

		close (pipefd[1]);	// Close the write end of parent
		wait(NULL);
		exit (0);
	} else if (pid == 0) {
		close (pipefd[1]);	// Close the write end of child
	//	printf ("In child process :\n");
	//	printf ("Input received from parent via pipe :\n");

		while ((read (pipefd[0], &child_buf, 1)) > 0) {
			if (child_buf == 27) break;
			else if ((child_buf == '\n') ||
				(child_buf == ' ')) continue;
			else printf("\"%c\" is read from pipe\n", child_buf);
		}

		close (pipefd[0]);	// Close the read end of child
		_exit (0);
	} else {
		errno_abort(pid, "fork() failed\n");
	}

	return 0;
}
