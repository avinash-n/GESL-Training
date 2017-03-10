/*
 * Avinash N
 * 06/02/2017
*/

/*
 * Write a program which will implement ls | wc.
*/

#include "errors.h"

int main (void) {
	pid_t pid;
	int pipefd[2];

	if (pipe(pipefd) == -1) errno_abort(-1, "pipe() failed\n");

	pid = fork();

	if (pid > 0) {
		dup2 (pipefd[1], 1);	// Duplicating stdout
		close (pipefd[0]);	// Close the read end of parent

		execlp ("ls", "ls", NULL);

	//	wait(NULL);
		exit (0);
	} else if (pid == 0) {
		dup2 (pipefd[0], 0);	// Duplicating stdin
		close (pipefd[1]);	// Close the write end of child

		execlp ("wc", "wc", NULL);

		_exit (0);
	} else {
		errno_abort(pid, "fork() failed\n");
	}

	return 0;
}
