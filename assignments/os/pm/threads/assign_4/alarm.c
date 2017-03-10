#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>

//#include <errors.h>

int main(int argc , char *argv[])
{
	int seconds;
	int status;
	char line[120];
	char message[64];
	int pid , pid2;
	time_t now;
	now = time(NULL);
	while(1){
		printf("alarm");
		if(fgets(line,sizeof(line),stdin) == NULL) exit(1);
		if(strlen(line) <= 1)continue;

		if(sscanf(line,"%d  %64[^\n]",&seconds,message)<2)
		{
			fprintf(stderr,"Bad command\n");
		}
		else{
			pid = fork();
			if(pid > 0) {
			signal(SIGCHLD,SIG_IGN);	
			}
			/*		if(pid >0)
					printf(" %s parent pid :%d\n",ctime(&now),getpid());
					if(pid == 0)
					printf("%s child  pid :%d\n",ctime(&now),getpid());
			 */
			/*if(pid>0)
			  printf("%s \t (%d) %s  parent\n",ctime(&now),seconds,message);*/
			else if(pid == 0) {
				sleep(seconds);
				printf("%s \t (%d) %s  child \n",ctime(&now),seconds,message);
				exit(0);
			}
		}

	}
} 
			
