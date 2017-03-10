/*
	Nmae: String copy
	Author: Avinash N
	Date: 18 November 2016
	Description: This program copies first n characters from source string
			into the destination string.
*/

#include<stdio.h>
#include<stdlib.h>
#include"mystring.h"

#define MAX_LENGTH 128

int main()
{
	char *src_str;		/* Source string */
	char *dst_str;		/* Destination string */
	char *n;		/* Number of characters to be copied */
//	int num;

	src_str = (char *) malloc(MAX_LENGTH);
	dst_str = (char *) malloc(MAX_LENGTH);
	n = (char *) malloc(MAX_LENGTH);

	printf("Enter the source string:\n");
	fgets(src_str, MAX_LENGTH, stdin);

	printf("Enter the number of charecters to be copied: ");
	fgets(n, MAX_LENGTH, stdin);
//	scanf("%d", &num);

	str_n_cpy(dst_str, src_str, validate(n));
//	str_n_cpy(dst_str, src_str, num);

	printf("The copied string is:\n");
	fputs(dst_str, stdout);

	free(src_str);
	free(dst_str);
	free(n);

	return 0;
}
