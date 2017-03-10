/*
	Name: Word count
	Author: Avinash N
	Date: 06 December 2016
	Description: This program will count the number of words
			in a given text file.
*/

#include "myheader.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	int count;

	VALIDATE_ARGC;

	fp = fopen(argv[1], "r");

	VALIDATE_FP;

	count = 0;

	while ((ch = fgetc(fp)) != EOF) {
		if (((ch == ' ') || (ch == '\0') || (ch == '\n'))) {
			count++;
		}
	}

	printf("Total number of words in %s: %d\n", argv[1], count);

	fclose(fp);
	return 0;
}
