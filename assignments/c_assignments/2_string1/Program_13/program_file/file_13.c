/*
	Name: Compare rotated strings
	Author: Avinash N
	Date: 20 November 2016
	Description: This program compares two strings and checks if
			second string is the rotated string of first string.
*/ 

#include<stdio.h>
#include<stdlib.h>
#include "mystring.h"

int main()
{
	char *src_str;
	char *rot_str;

	src_str = (char *) malloc(MAX_STRING_LENGTH);
	rot_str = (char *) malloc(MAX_STRING_LENGTH);

	printf("Enter the first string:\n");
	fgets(src_str, MAX_STRING_LENGTH, stdin);

	printf("Enter the second string:\n");
	fgets(rot_str, MAX_STRING_LENGTH, stdin);

	if (!(str_r_cmp(src_str, rot_str))) {
		printf("Second string is the rotated string of first string\n");
	} else {
		printf("Second string is not the rotated string\n");
	}

	return 0;
}
