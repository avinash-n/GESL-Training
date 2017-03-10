/*
	Name: String copy
	Author: Avinash N
	Date: 17 November 2016
	Description: This program copies entire source
			string into the destination string.
*/

#include<stdio.h>
#include<stdlib.h>
#include"mystring.h"

#define MAX_LENGTH 128

int main()
{
	char *src_str;		/* Source string */
	char *dst_str;		/* Destination string */

	src_str = (char *) malloc(MAX_LENGTH);
	dst_str = (char *) malloc(MAX_LENGTH);

	printf("Enter the source string:\n");
	fgets(src_str, MAX_LENGTH, stdin);

	string_copy(dst_str, src_str);

	printf("The copied string is:\n");
	fputs(dst_str, stdout);

	return 0;
}
