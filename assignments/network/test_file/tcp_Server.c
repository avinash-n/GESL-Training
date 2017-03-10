#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int sock_fd = socket(AF_INET,SOCK_STREAM,0);
	int l,b,new_fd;
	char *s1 = (char *)malloc(30);
	if(sock_fd == -1){
			perror("session is not opened\n");
			return 0;
	}
	struct sockaddr_in addr;
	struct sockaddr_in *client = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
	int *size = (int *)malloc(sizeof(int));
		addr.sin_family = AF_INET;
		addr.sin_port = htons(1234);
		addr.sin_addr.s_addr = INADDR_ANY;
		b = bind(sock_fd,(struct sockaddr *)&addr,sizeof(struct sockaddr_in));
		if(b == -1){
			perror("bind system call is not sucessful\n");
			return 0;
		}
		l = listen(sock_fd,3);
		if(l == -1){
				perror("listen system call is failed\n");
				return 0;
		}
		new_fd = accept(sock_fd,(struct sockaddr *)&client,size);
		printf("new file desc is %d\n",new_fd);
		getchar();
		if(new_fd == -1){
				perror("new connection is failed\n");
				return 0;
		}
		read(new_fd,s1,30);
		printf("server recived data %s\n",s1);
		write(new_fd,"nikhila",30);
		
		close();	

}
