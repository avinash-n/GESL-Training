/*
	Name: Swap bits
	Author: Avinash N
	Date: 10/11/2016
	Description: This program will swap two bits in a given number
*/

#include<stdio.h>
#include<stdlib.h>

extern int showbits(int);
extern int mask(int, int);
int swap_bits(int, int, int);

int main(void)
{
	int num;
	int src_pos;		/* Source bit position */
	int dst_pos;		/* Destination bit position */

	printf("Enter a number:");
	scanf("%d", &num);

	printf("Enter source bit position:");
	scanf("%d", &src_pos);

	printf("Enter destination bit position:");
	scanf("%d", &dst_pos);

	if(num >= 0 && src_pos >= 0 && dst_pos >= 0) {
		printf("The entered number is:\n");
		showbits(num);
		num = swap_bits(num, src_pos, dst_pos);

		printf("The n umber after swapping bits:\n");
		showbits(num);
	} else {
		printf("Invalid input!\n");
	}

	return 0;
}

/* Function to swap the bits */
int swap_bits(int f_num, int f_src_pos, int f_dst_pos)
{
	int mask1;
	int mask2;

	mask1 = (f_num & (mask(f_src_pos,1)));
	mask2 = (f_num & (mask(f_dst_pos,1)));

	if(mask1 == mask2) {
		printf("Swapping is not required\n");
	} else {
		f_num = f_num ^ ((1 << f_src_pos) | (1 << f_dst_pos));

	}
	return f_num;
}
