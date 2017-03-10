/*
	Name: Get bits
	Author: Avinash N
	Date:
	Description: This program returns n-bits (left adjusted) of x
			starting at position p.
*/

#include<stdio.h>
#include<stdlib.h>

#define getbits (mask(pos, bits) & num)

extern int showbits(unsigned int);
extern int mask(int, int);

int main()
{
	unsigned int num;
	int pos;		/* Starting postion */
	int bits;		/* Number of bits */

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Enter the starting position:");
	scanf("%d", &pos);

	printf("Enter the number of bits:");
	scanf("%d", &bits);

	showbits(getbits);

	return 0;
}
