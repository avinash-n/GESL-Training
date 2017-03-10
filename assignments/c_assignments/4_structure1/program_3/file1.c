/*
	Name: Check the endianess
	Author: Avinash N
	Date: 24 November 2016
	Description: This program will check for the endianess of the machine.
*/

#include <stdio.h>
#include <stdlib.h>

struct endian
{
	unsigned int num;
	char *ch;
};

int main()
{
	struct endian object;

	object.num = 1;
	object.ch = &(object.num);


	if (*(object.ch) == 0) {
		printf("The machine is Big Endian\n");
	} else {
		printf("The machine is Little Endian\n");
	}

	return 0;
}
