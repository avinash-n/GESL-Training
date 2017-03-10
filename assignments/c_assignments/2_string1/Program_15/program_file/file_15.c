/*
	Name: Insert character
	Author: Avinash N
	Date: 20 November 2016
	Description: This program will insert a character into a string
			at a given position.
*/

#include<stdio.h>
#include<stdlib.h>
#include "mystring.h"

int main()
{
	char *str;
	char *ch;
	int pos;

	str = (char *) malloc(MAX_STRING_LENGTH);
	ch = (char *) malloc(5);

	printf("Enter a string:\n");
	fgets(str, MAX_STRING_LENGTH, stdin);

	printf("Enter the character to be inserted: ");
	fgets(str, 5, stdin);

	printf("Enter the position to insert the character: ");
	scanf("%d", &pos);

	chr_ins(str, ch, pos);

	printf("String after inserting '%s' at position '%d':\n", ch, pos);
	fputs(str, stdout);

	free(str);
	free(ch);

	return 0;
}
