/*
	Name: Append two strings
	Author: Avinash N
	Date: 20 November 2016
	Description: This program appends a string at the end of another string.
*/

#include<stdio.h>
#include<stdlib.h>
#include "mystring.h"

int main()
{
	char *str_1;
	char *str_2;

	str_1 = (char *) malloc(MAX_STRING_LENGTH);
	str_2 = (char *) malloc(MAX_STRING_LENGTH);

	printf("Enter the first string:\n");
	fgets(str_1, MAX_STRING_LENGTH, stdin);

	printf("Enter the second string:\n");
	fgets(str_2, MAX_STRING_LENGTH, stdin);

	str_cat(str_1, str_2);

	printf("Resulting string after appending:\n");
	fputs(str_1, stdout);

	free(str_1);
	free(str_2);

	return 0;
}
