/*
 * Avinash N
 * 26 - 01 - 2017
 */

/*
 * Write a shell program using fork() and exec().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define STR_LEN 32

#define VALIDATE(str) if (!str) {\
	perror("Malooc failed!\n");\
	exit(1);\
}

int main (void) {
	pid_t pid;
	char *argv[10];

	char *cmd = NULL;
	cmd = (char *) malloc (sizeof(char) * STR_LEN);
	VALIDATE(cmd);

//	while (1) {
		printf("Enter the command to execute: ");
		fgets(cmd, STR_LEN, stdin);
		VALIDATE(cmd);

		*(cmd + strlen(cmd) -1) = '\0';

		printf("Output of %s command:\n", cmd);
//		if (!strcmp(cmd, "exit()"))
//			exit(0);
			
		strcpy(argv[0], cmd);
		argv[1] = NULL;

		//printf("%s\n", *argv);
		pid = fork();


		if (pid == 0) {
			execvp(cmd, argv);
		} else if (pid > 0) {
			wait(NULL);
		//	printf("Enter exit() to leave\nPress any key to continue\n");
		//	fgets(cmd, STR_LEN, stdin);
		//	VALIDATE(cmd);
		}
//	}
//	free(cmd);
//	cmd = NULL;

	return 0;
}
