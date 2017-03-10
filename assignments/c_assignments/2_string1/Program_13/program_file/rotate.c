/* This function compares two strings in reverse */
#include "mystring.h"

int str_r_cmp(char *f_src_str, char *f_rot_str)
{
	int i;
	int length;
	int flag;

	flag = 0;

	if (((length = str_len(f_src_str)) == str_len(f_rot_str))) {
		for (i = 0; *(f_src_str+i) != '\n'; i++) {
			if (((*(f_src_str+i)) != (*(f_rot_str+length-i-1)))) {
				flag = 1;

			}
		}
	} else {
		flag = 1;
	}

	return flag;
}
