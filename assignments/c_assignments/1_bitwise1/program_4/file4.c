/*
	Name: Toggle bits
	Author: Avinash N
	Date:
	Description: This program will give the number output after toggling
			even and odd bits respectively.
*/

#include<stdio.h>
#include<stdlib.h>

int even_bit_toggle(int);
int odd_bit_toggle(int);
extern int showbits(int);

int main()
{
	unsigned int num;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Number after toggling even bits:\n");
	showbits(even_bit_toggle(num));

	printf("\nNumber after toggling odd bits:\n");
	showbits(odd_bit_toggle(num));

	return 0;
}

int even_bit_toggle(int e_num)
{
	int bit_length;
	int mask;

	mask = 2;
	bit_length = 4 * sizeof(void *);

	for(; bit_length >=1; bit_length--) {
		e_num = e_num ^ mask;
		mask = mask << 2;
	}

	return e_num;
}

int odd_bit_toggle(int o_num)
{
	int bit_length;
	int mask;

	mask = 1;
	bit_length = 4 * sizeof(void *);

	for(; bit_length >= 1; bit_length--) {
		o_num = o_num ^ mask;
		mask = mask << 2;
	}

	return o_num;
}
