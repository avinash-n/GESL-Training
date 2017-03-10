/*
	Name: Reverse string
	Author: Avinash N
	Date: 19 November 2016
	Description: This program will reverse the given source string
			and returns the new reversed string.
*/

#include<stdio.h>
#include<stdlib.h>
#include "mystring.h"

#define MAX_STRING_LENGTH 128

int main()
{
	char *src_str;
	char *rev_str;

	src_str = (char *) malloc(MAX_STRING_LENGTH);
	rev_str = (char *) malloc(MAX_STRING_LENGTH);

	printf("Enter the string:\n");
	fgets(src_str, MAX_STRING_LENGTH, stdin);

	str_rev(rev_str, src_str);

	printf("Reversed string is:");
	fputs(rev_str, stdout);
	printf("\n");

	return 0;
}
