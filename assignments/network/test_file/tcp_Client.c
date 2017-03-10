#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int sock_fd = socket(AF_INET,SOCK_STREAM,0);
	int l,b,size;
	char *s1 = "hi hello";
	char *s2 =(char *)malloc(30);
	if(sock_fd == -1){
			perror("session is not opened\n");
			return 0;
	}
	struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(1234);
		addr.sin_addr.s_addr = INADDR_ANY;
		size = sizeof(struct sockaddr_in);
		int c = connect(sock_fd,(struct sockaddr *)&addr,size);
		if(c == -1){
				perror("new connection is failed\n");
				return 0;
		}
		write(sock_fd,s1,30);
		getchar();
		read(sock_fd,s2,30);
		printf("in client recieved data %s\n",s2);
		close();	

}
