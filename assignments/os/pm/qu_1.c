/*
 * 23 - 01 - 2017
 * Write a shell program using fork and exec.
 * Ensure that you will not retain any zombie process.
 */

#include <stdio.h>
#include <linux/sched.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(void) {
	pid_t pid;

	printf("In parent process\n");

	printf("PID before fork() --> %d\n", getpid());

	pid = fork();

//	getchar();
	printf("Value returned by fork() --> %d\n", pid);

	printf("PID after fork() --> %d\n", getpid());

//	getchar();
//	wait();
//	getchar();
//	printf("After fork() --> %d\n", getpid());

	return 0;
}
