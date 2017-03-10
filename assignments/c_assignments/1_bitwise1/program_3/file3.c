/*
	Name: Copy n bits
	Author: Avinash N
	Date:
	Description: Program to copy n bits from source number
			to destination number
*/

#include<stdio.h>

extern int showbits(int num);
int bit_copy(int snum, int dnum, int n, int s, int d);

int main()
{
	int snum;	/* Source number */
	int dnum;	/* Destination number */
	int n;		/* Number of bits to copy */
	int s;		/* Source position */
	int d;		/* Destination position */
	int res;	/* Resulting number */
	
	printf("Enter the source number\n");
	scanf("%d", &snum);
	showbits(snum);	
	
	printf("Enter the destination number\n");
	scanf("%d", &dnum);
	showbits(dnum);
	
	printf("Enter the source bit position\n");
	scanf("%d", &s);
	
	printf("Enter the bits to be copied\n");
	scanf("%d", &n);
	
	printf("Enter the destination bit position\n");
	scanf("%d", &d);

	res = bit_copy(snum, dnum, n, s, d);// Invoking function
	printf("The number with bit copy:\n");
	showbits(res);
	return 0;
}

int bit_copy(int snum, int dnum, int n, int s, int d)
{
	int i;
	int j;
	int k;
	for(i = 0; i < n; i++) {
		j = (snum >> (s-i)) & 1;
		k = (dnum >> (d-i)) & 1;
		if(j != k) {
			dnum = dnum ^ (1 << (d-i));
		}
	}
	return dnum;
}
