//Program to swap bit from one number to another number

#include<stdio.h>

extern int showbit(int num);// extern function to showbit

int main()
{
	int snum;
	int dnum;
	int s;
	int d;

	printf("WELCOME TO SWAP BIT FOR 2 NUMBERS\n");
	printf("Enter source numbers\n");
	scanf("%d", & snum);
	printf("Enter destination numbers\n");
	scanf("%d", & dnum);
	printf("The numbers before swap\n");
	showbit(snum);
	printf("\n");
	showbit(dnum);
	printf("Enter the source and destination position\n");
	scanf("%d%d", & s, & d);
	
	if((1 & (snum >> s)) != (1 & (dnum >> d))) 
		{
			snum = (1 << s) ^ snum;
			dnum = (1 << d) ^ dnum;
		}
			printf("The numbers after swap\n");
			showbit(snum);
			printf("\n");
			showbit(dnum);
			return 0;
}
