/* Program to print the bits of a number */
#include<stdio.h>

int showbits(int s_num)
{
	int bit_size;
	int count;

	count = 0;
	
	bit_size = 8 * sizeof(void *);
	for(; bit_size >= 1; bit_size--) {
		printf("%d", (1 & (s_num >> (bit_size - 1))));
		count++;
		if(count % 8 == 0)
			printf(" ");
	}
	printf("\n");
	return 0;
}
