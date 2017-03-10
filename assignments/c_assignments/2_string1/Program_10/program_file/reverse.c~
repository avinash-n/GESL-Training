/* String reverse */
#include "mystring.h"
void str_rev(char *f_rev_str, char *f_src_str)
{
	int length;
	int i;

	length = str_len(f_src_str);

	for (i = 0; i < length && *f_src_str != '\0'; i++) {
		(*(f_rev_str+i) = *(f_src_str+(length - 1 - i)));
	}

	*(f_rev_str+i) = '\0';
}
