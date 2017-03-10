/*
	Name: Set a bit
	Author: Avinash N
	Date: 
	Description: This program will test and set a bit position in a number.
*/

#include<stdio.h>
#include<stdlib.h>

#define bit_ts (num | (1 << pos))

extern int showbits(int);

int main()
{
	unsigned int num;
	int pos;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Enter the position of bit to set:");
	scanf("%d", &pos);

	printf("Number after setting a bit at position %d:\n", pos);
	showbits(bit_ts);

	return 0;
}
