#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void get_ctrlC (int sig_num) {
	printf("Detected Ctrl+c\n");
	fflush(stdout);
}

int main (void) {	
	signal(SIGINT, get_ctrlC);

	printf("Hello\n");

	pause();

	return 0;
}
