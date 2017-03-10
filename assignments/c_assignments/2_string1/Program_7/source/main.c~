/*
	Name: String case compare
	Author: Avinash N
	Date: 24 November 2016
	Description: 
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *src;
	char *dst;
	char *temp1;
	char *temp2;
	int n;
	int m1;
	int m2;
	int i;

	src = (char *) malloc(sizeof(char)*LENGTH);
	dst = (char *) malloc(sizeof(char)*LENGTH);
	temp1 = (char *) malloc(sizeof(char)*LENGTH);
	temp2 = (char *) malloc(sizeof(char)*LENGTH);

	printf("enter the string: ");
	fgets(src, LENGTH, stdin);

	printf("enter the 2nd string: ");
	fgets(dst, LENGTH, stdin);

	m1 = stringlength(src);
	m2 = stringlength(dst);

	for(i = 0; i < m1; i++) {
		if((*(src + i) >= 'A') && (*(src + i) <= 'Z')) {
			*(temp1 + i) = *(src + i) + 32;
		} else {
			*(temp1 + i) = *(src + i);
		}
	}
	*(temp1 + m1) = '\0';

	for(i = 0; i < m2; i++) {
		if((*(dst + i) >= 'A') && (*(dst + i) <= 'Z')) {
			*(temp2 + i) = *(dst + i) + 32;
		} else {
			*(temp2 + i) = *(dst + i);
		}
	}
	*(temp2 + m2) = '\0';
	printf("%s%s",temp1,temp2);
	n = stringcompareci(temp1, temp2);

	if ( n == 0) {
		printf("strings are same");
	} else if (n == 1) {
		printf("%s string is greater", src);
	} else {
		printf("%s string is greater", dst);
	}
	free(src);
	free(dst);
	free(temp1);
	free(temp2);
	return 0;
}

