/* This function appends two strings */

#include "mystring.h"

void str_cat(char *f_str_1, char *f_str_2)
{
	int i;
	int length;

	length = str_len(f_str_1);

	for (i = 0; (*(f_str_2+i) != '\0'); i++) {
		*(f_str_1+length+i) = *(f_str_2+i);
	}

	*(f_str_1+length+i) = '\0';
}
