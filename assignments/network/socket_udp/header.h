#ifndef header_h
#define header_h 1

#include <sys/socket.h>
#include <linux/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifndef _NETINET_IN_H
#define _NETINET_IN_H 1
#ifndef _ARPA_INET_H
#define _ARPA_INET_H 1

#define MAX_BUF 108

#define error_handler(msg) { \
		perror (msg); \
		exit (EXIT_FAILURE); \
		}

#endif
#endif
#endif
