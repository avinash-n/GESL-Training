/*
	This function will convert the entered character into its equivalent
	integer and check for validation.
*/

#include<stdio.h>
#include<stdlib.h>
int validate(char *f_n)
{
	int n;			/* To store the converted integer value */
	int i;

	n = 0;

	for (i = 0; *f_n+i >= '0' && *f_n+i <= '9'; i++) { 	
		n = n * 10 + (*f_n+i - '0');
	}
	printf("%d", n);

//	if (*f_n == '-') {
//		return (-1);
//	} else {
		return n;
//	}
}
