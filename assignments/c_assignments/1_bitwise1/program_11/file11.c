/*
	Name: Invert bits
	Author: Avinash N
	Date:
	Description: This program inverts n bits of a given number
			starting at position p leaving other bits unchanged.
*/

#include<stdio.h>
#include<stdlib.h>

#define invert (mask(pos, bits) ^ num)

extern int showbits(unsigned int);
extern int mask(int, int);

int main()
{
	unsigned int num;
	unsigned int i_num;
	int pos;
	int bits;

	printf("Enter a number:");
	scanf("%d", &num);
	
	showbits(num);

//	if (valid(i_num)) {
//		printf("Entered number is:");

	printf("Enter the starting position:");
	scanf("%d", &pos);

	printf("Enter the number of bits:");
	scanf("%d", &bits);

	i_num = invert;

	printf("Number after invertion:\n");
	showbits(i_num);

	return 0;
}
