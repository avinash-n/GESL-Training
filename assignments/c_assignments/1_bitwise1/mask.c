/* Program to generate mask */
#include<stdio.h>

// extern int showbits(int);

int mask(int pos, int bits)
{
	int i;
	unsigned int m;

	i = 8 * sizeof(int);
	m = ~(0);
	m = m << (i - bits);
	m = m >> (i - 1 - pos);
//	showbits(m);
	return m;
}
