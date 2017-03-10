/* This function will insert a character into the string at given position */

#include<stdio.h>
#include "mystring.h"

void chr_ins(char *_str, char *f_ch, int f_pos)
{
	int length;
	int i;

	length = str_len(_str);

	printf("%d\n", length);

	for (i = length; i > 0; i--) {
		if (i != f_pos) {
			(*(_str+i+1)) = (*(_str+i));
		} else {
			(*(_str+i+1)) = (*(f_ch));
		}
	}
} 
