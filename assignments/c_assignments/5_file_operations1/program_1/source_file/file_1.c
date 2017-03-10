/*
	Name: Case conversion
	Author: Avinash N
	Date: 28 November 2016
	Description: This program will convert all upper case letters
			to lower case letters in a given text file.
*/

#include "myheader.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;

	if (argc <= 1) {
		printf("Insufficient input!\n");
		exit(0);
	}

	fp = fopen(argv[1], "r");

	if (fp == 0) {
		printf("File could not be opened!\n");
		exit(0);
	}

	case_convert(fp);

	return 0;
}
