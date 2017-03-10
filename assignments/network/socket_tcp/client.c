#include "header.h"

#define SER_PORTNO 6793
#define SER_IPADDR 0xac100565

int main (int argc, char *argv[]) {
	int sockfd;
	int newfd;
	struct sockaddr_in s_addr;	// Server
	struct sockaddr_in c_addr;	// Client
	char *buf = NULL;	// Buffer to store received data
	socklen_t size = sizeof (struct sockaddr_in);

	if ((buf = (char *) malloc (sizeof (char) * MAX_BUF)) == NULL)
		error_handler("malloc(buf) failed\n");

	sockfd = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd == -1) error_handler("socket() failed\n");

	memset (&s_addr, '\0', sizeof (struct sockaddr_in));	// Clear structure	

	s_addr.sin_family = PF_INET;
	s_addr.sin_port = htons (SER_PORTNO);
	s_addr.sin_addr.s_addr = htonl (SER_IPADDR);

	if (connect (sockfd, (struct sockaddr *)&s_addr, size) == -1)
		error_handler("sendto() failed\n");

	do {
		memset (buf, '\0', MAX_BUF);	// Clear buffer	
		strcpy (buf, "I am client\n");

		write (sockfd, buf, MAX_BUF);
		memset (buf, '\0', MAX_BUF);	// Clear buffer	

		read (sockfd, buf, MAX_BUF);
		printf ("Response received\n");
		fwrite (buf, MAX_BUF, 1, stdout);
	} while (getchar() == '\n');

	close(newfd);
	close(sockfd);

	return 0;
}
