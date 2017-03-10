/*
	This function copies first n characters from a source string
	into the destination string
*/
#include<stdio.h>
#include<stdlib.h>

void str_n_cpy(char *f_dst_str, char *f_src_str, int f_n)
{
	int i;

	for (i = 0; ((i < f_n) && (*f_src_str != '\0')); i++) {
		*f_dst_str++ = *f_src_str++;
	}
	*f_dst_str = '\0';
	fputs(f_dst_str, stdout);
}
