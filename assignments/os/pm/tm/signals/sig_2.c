/*
 * Avinash N
 * 26/01/2017
*/

/*
 * Program to handle ctrl + c and segfault using sigaction()
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/compiler.h>
#include <unistd.h>

int i = 0;

void sigaction_handler(int sig_num, siginfo_t *field, void *temp) {
	if (sig_num == SIGINT) {
		printf("Detected Ctrl + C \n");
	exit(1);
	} else if (sig_num == SIGSEGV) {
		printf("Detected Segmentation fault\n");
		printf("PID --> %d\nAddress --> %p\n", field->si_pid, field->si_addr);
		printf("PID --> %d\n", field->si_signo);
		printf("PID --> %d\n", field->si_errno);
		printf("PID --> %d\n", field->si_code);
		printf("PID --> %d\n", field->si_uid);
		printf("PID --> %d\n", field->si_status);
		printf("PID --> %d\n", field->si_call_addr);
		printf("PID --> %d\n", field->si_value);
		printf("PID --> %p\n", field->si_ptr);
	exit(1);
	}
	fflush(stdout);
	i = 0;
}


int main (void) {
	int *ptr = NULL;
	struct sigaction act;
	act.sa_sigaction = &sigaction_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction (SIGINT, &act, NULL);
	sigaction (SIGSEGV, &act, NULL);

	ptr = 1000;
	*ptr = 100;
/*	while(1) {
		printf("%d\n", i++);
	}
//pause();	// Halt the process when received a signal
*/
	return 0;
}
