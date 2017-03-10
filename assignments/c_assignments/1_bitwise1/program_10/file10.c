/*
	Name: Set bits
	Author: Avinash N
	Date: 
	Description: This program returns x with the n bits
			that begin at position p set to the right most n bits
			of y, leaving the other bits unchanged.
*/

#include<stdio.h>
#include<stdlib.h>

#define setbits (mask(pos, bits) | i_num)

extern int showbits(int);
extern int mask(int, int);

int main()
{
	unsigned int i_num;
	unsigned int r_num;
	int pos;
	int bits;

	printf("Enter two numbers:");
	scanf("%d%d", &i_num, &r_num);

	showbits(i_num);
	showbits(r_num);

	printf("Enter the starting position:");
	scanf("%d", &pos);

	printf("Enter the number of bits:");
	scanf("%d", &bits);

	r_num = setbits;

	printf("Number after setting bits:\n");
 
	showbits(r_num);

	return 0;
}
