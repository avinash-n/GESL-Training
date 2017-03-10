/*
	Name: Implementing strspn()
	Author: Avinash N
	Date: 24 November 2016
	Description: 
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *buf1;
	char *buf2;
	int  n;

	buf1 = (char *) malloc(sizeof(char)*LENGTH);
	buf2 = (char *) malloc(sizeof(char)*LENGTH);

	printf("enter the string: ");
	fgets(buf1, LENGTH, stdin);

	printf("enter the search string ");
	fgets(buf2, LENGTH, stdin);

	n = stringspn(buf1, buf2);

	printf("the number of intial set of char found in buf1: %d\n",n);
	free(buf1);
	free(buf2);
	return 0;
}

