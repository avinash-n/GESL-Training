/*
 * Avinash N
 * 26/01/2017
*/

/*
 * Program to handle ctrl + c  using signal()
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int i = 0;

void get_ctrlC (int sig_num) {
	printf("Detected Ctrl + C \n");
	fflush(stdout);
//	exit(1);
	i = 0;
}

int main (void) {

	signal (SIGINT, get_ctrlC);

		while(1) {
			printf("%d\n", i++);
		}
//pause();	// Halt the process when received a signal

	return 0;
}
