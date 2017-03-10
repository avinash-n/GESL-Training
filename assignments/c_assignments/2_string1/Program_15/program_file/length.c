/* This function finds the length of a given string */

#include<stdio.h>

int str_len(char *f_str)
{	
	int count;

	for (count = 0; *(f_str+count) != '\0'; count++) ;

	printf("%d\n", count);
	return count-1;
}
