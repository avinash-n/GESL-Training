/*
	Name: Shrink string
	Author: Avinash N
	Date: 20 November 2016
	Description: This program squeezes the consecutive similar characters
			in a given string.
*/

#include<stdio.h>
#include<stdlib.h>
#include "mystring.h"

#define MAX_STRING_LENGTH 128

int main()
{
	char *src_str;
	char *res_str;

	src_str = (char *) malloc(MAX_STRING_LENGTH);
	res_str = (char *) malloc(MAX_STRING_LENGTH);

	printf("Enter a string:\n");
	fgets(src_str, MAX_STRING_LENGTH, stdin);

	str_squeeze(res_str, src_str);

	printf("The string after squeezing consecutive characters:\n");
	fputs(res_str, stdout);

	free(src_str);
	free(res_str);

	return 0;
} 
