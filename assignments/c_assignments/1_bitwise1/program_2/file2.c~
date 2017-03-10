/*
	Name: Swap bits between two numbers
	Author: Avinash N
	Date:
	Description: This program swaps a bit at a given position of number1
			with a bit at a given position of number2.
*/

#include<stdio.h>
#include<stdlib.h>

extern int showbits(int);
extern int mask(int, int);
extern int validate(char *);

int swap_bits(unsigned int, unsigned int, int, int);

int main()
{
	char num1;
	char num2;
	unsigned int src_num;	/* Source number */
	unsigned int dst_num;	/* Destination number */
	int src_pos;		/* Source bit position in source number */
	int dst_pos;		/* Destination bit position in destination number */

	printf("Enter source number:");
	scanf("%s", &num1);

	src_num = validate(num1);
	if (src_num) {
		printf("Enter destination number:");
		scanf("%s", &num2);
	}

	dst_num = validate(num2);
	if (dst_num) {
		showbits(num1);
		showbits(num2);
	}

	printf("Enter source bit position:");
	scanf("%d", &src_pos);

	printf("Enter destination bit position:");
	scanf("%d", &dst_pos);

	printf("Numbers after swapping bits:\n");
	swap_bits(num1, num2, src_pos, dst_pos);

	return 0;
}

int swap_bits(unsigned int f_num1, unsigned int f_num2,
				int f_src_pos, int f_dst_pos)
{
	int mask1;
	int mask2;

	mask1 = (f_num1 & (mask(f_src_pos, 1)));
	mask2 = (f_num2 & (mask(f_dst_pos, 1)));

	if ( f_src_pos < f_dst_pos) {
		mask1 = mask1 << (f_dst_pos - f_src_pos);
		if (mask1 == mask2) {
			printf("Swapping is not required");
		} else {
			f_num1 = f_num1 ^ (1 << f_src_pos);
			f_num2 = f_num2 ^ (1 << f_dst_pos);
		}
	} else if (f_src_pos > f_dst_pos) {
		mask1 = mask1 >> (f_src_pos - f_dst_pos);
		if (mask1 == mask2) {
			printf("Swapping is not required");
		} else {
			f_num1 = f_num1 ^ (1 << f_src_pos);
			f_num2 = f_num2 ^ (1 << f_dst_pos);
		}
	} else {
		if (mask1 == mask2) {
			printf("Swapping is not required");
		} else {
			f_num1 = f_num1 ^ mask1;
			f_num2 = f_num2 ^ mask2;
		}
	}


	showbits(f_num1);
	showbits(f_num2);

	return 0;
}
