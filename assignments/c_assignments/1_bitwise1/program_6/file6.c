/*
	Name: Rotate a number
	Author: Avinash N
	Date:
	Description:
*/

#include<stdio.h>
#include<stdlib.h>

#define BIT_LENGTH 8 * sizeof(void *)

unsigned int left_rotate_bits(unsigned int);
unsigned int right_rotate_bits(unsigned int);
unsigned int left_rotate_n_bits(unsigned int, int);
unsigned int right_rotate_n_bits(unsigned int, int);

extern int mask(int, int);
extern int showbits(int);

# if 0
int main()
{
	unsigned int num;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	showbits(left_rotate_bits(num));

	return 0;
}

unsigned int left_rotate_bits(unsigned int f_num)
{
	return (f_num << 1) | ((f_num & (1 << (BIT_LENGTH - 1))) >> (BIT_LENGTH - 1));
}
# endif

# if 0
int main()
{
	unsigned int num;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	showbits(right_rotate_bits(num));

	return 0;
}

unsigned int right_rotate_bits(unsigned int f_num)
{
	return (f_num >> 1) | ((f_num & 1 ) << (BIT_LENGTH - 1));
}
# endif

# if 0
int main()
{
	unsigned int num;
	int bits;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Enter number of bits to rotate:");
	scanf("%d", &bits);

	printf("Number after rotating %d bits to left:\n", bits);
	showbits(left_rotate_n_bits(num, bits));

	return 0;
}

unsigned int left_rotate_n_bits(unsigned int f_num, int f_bits)
{
	return (f_num << f_bits) | ((f_num & ((mask(f_bits - 1, f_bits)) << (BIT_LENGTH - f_bits))) >> (BIT_LENGTH - f_bits));
}
# endif

# if 1
int main()
{
	unsigned int num;
	int bits;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Enter number of bits to rotate:");
	scanf("%d", &bits);

	printf("Number after rotating %d bits to right:\n", bits);
	showbits(right_rotate_n_bits(num, bits));

	return 0;
}

unsigned int right_rotate_n_bits(unsigned int f_num, int f_bits)
{
	return (f_num >> f_bits) | ((f_num & (mask(f_bits - 1, f_bits))) << (BIT_LENGTH - f_bits));
}
# endif

