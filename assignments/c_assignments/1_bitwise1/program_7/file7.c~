/*
	Name: Count bits
	Author: Avinash N
	Date:
	Description: This program will count the number of set bits
			and clear bits in a number.
*/

#include<stdio.h>
#include<stdlib.h>

#define count_bit (num & (num - 1))

extern int showbits(int);

int main()
{
	unsigned int num;
	int count;
	int bit_length;

	count = 0;
	bit_length = 8 * sizeof(void *);

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	while (num > 0) {
		count++;
		num = count_bit;
	}

	printf("Number of set bits: %d", count);
	printf("\nNumber of clear bits: %d\n", (bit_length - count));

	return 0;
}
