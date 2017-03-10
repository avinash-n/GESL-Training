#include "header.h"

int asciitoint(char *s)
{
	int i;
	int n = 0;

	for(i = 0; (*(s + i) >= '0') && (*(s + i) <= '9'); i++) {
		n = (n * 10) + (*(s + i) - '0');
	}
	printf("n = %d\n",n);
	return n;
}
