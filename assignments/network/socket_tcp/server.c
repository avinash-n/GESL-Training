#include "header.h"

#define SER_PORTNO 6792
#define SER_IPADDR INADDR_ANY

int main (int argc, char *argv[]) {
	int sockfd;
	int newfd;
	struct sockaddr_in s_addr;	// Server
	struct sockaddr_in c_addr;	// Client
	char *buf = NULL;	// Buffer to store received data
	socklen_t size = sizeof(struct sockaddr_in);

	if ((buf = (char *) malloc (sizeof (char) * MAX_BUF)) == NULL)
		error_handler("malloc(buf) failed\n");

	sockfd = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd == -1) error_handler("socket() failed\n");

	memset (&s_addr, '\0', sizeof (s_addr));	// Clear structure	

	s_addr.sin_family = PF_INET;
	s_addr.sin_port = htons (SER_PORTNO);
	s_addr.sin_addr.s_addr = htonl (SER_IPADDR);

	if (bind (sockfd, (struct sockaddr *)&s_addr, sizeof (struct sockaddr_in)) == -1)
		error_handler("bind() failed\n");

	if (listen (sockfd, 4) == -1)
		error_handler("recvfrom() failed\n");

	do {
		memset (buf, '\0', MAX_BUF);	// Clear buffer	

		if ((newfd = accept (sockfd, (struct sockaddr *)&c_addr, &size)) == -1)
			error_handler("accept() failed\n");

		printf ("Request received\n");
		read (newfd, buf, MAX_BUF);
		fwrite (buf, MAX_BUF, 1, stdout);

		memset (buf, '\0', MAX_BUF);	// Clear buffer	
		strcpy (buf, "I am server");
		write (newfd, buf, MAX_BUF);

	} while (getchar() == '\n');

	close(sockfd);

	return 0;
}
