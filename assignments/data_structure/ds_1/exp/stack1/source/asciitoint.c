#include "header.h"

int asciitoint(char *s)
{
	int i = 0;
	int n;

	for(i = 0; *(s + i) >= '0' && *(s + i) <= '9'; i++) {
		n = n * 10 + ( *(s + i) - '0');
		return n;
	}
}
