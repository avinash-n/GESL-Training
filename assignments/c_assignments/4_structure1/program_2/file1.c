/*
	Name: Implement Union
	Author: Avinash N
	Date: 24 November 2016
	Description: This program will describe the implementation of union.
*/

#include <stdio.h>
#include <stdlib.h>

union sample
{
	int a:5;
	int b:10;
	int c:5;
	int d:21;
	int e;
};

int main()
{
	union sample object;

	printf("Enter the value to initialize the last element of union: ");
	scanf("%d", &object.e);

	printf("Value of union members:\n");
	printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\n",
		object.a, object.b, object.c, object.d, object.e);

	return 0;
}
