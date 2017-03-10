/*
	Name: Character address
	Author: Avinash N
	Date: 20 November 2016
	Description: This program returns the address of first occurance
			of a character in a string.
*/

#include<stdio.h>
#include<stdlib.h>
#include "mystring.h"

int main()
{
	char *str;
	char *ch;
	unsigned int addr;

	str = (char *) malloc(MAX_STRING_LENGTH);
	ch = (char *) malloc(2);

	printf("Enter the string:\n");
	fgets(str, MAX_STRING_LENGTH, stdin);

	printf("Enter the character to find the address: ");
	fgets(ch, 2, stdin);

	addr = chr_addr(str, ch);
 
	if (addr != 1) {
		printf("'%s' is first found at 0x%x\n", ch, addr);
	} else {
		printf("'%s' is not found in the string\n", ch);
	}

	return 0;
}
