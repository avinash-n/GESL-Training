/*
 * Avinash N
 * 28/01/2017
*/

/*
 * Assignment 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void) {
	int seconds;
	char line[120];
	char message[64];
	pid_t pid;

	while (1) {
		printf ("Alarm () : ");
		if (fgets (line, sizeof (line), stdin) == NULL) exit (0);
		if (strlen (line) <= 1) continue;

		if (sscanf (line, "%d %64[^\n]", &seconds, message) < 2 ) {
			fprintf (stderr, "Bad command\n");
		} else {
			pid = fork();

			if (pid == 0) {
				sleep (seconds);
				printf("(%d) %s\n", seconds, message);
				exit(0);
			} else if (pid > 0) {
				signal (SIGCHLD, SIG_IGN);
				continue;
			} else {
				printf ("fork() failed\n");
				exit(1);
			}
		}
	}
	return 0;
}
