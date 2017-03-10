/* Compare two strings */
#include"mystring.h"
int str_cmp(char *f_str_2, char *f_str_1)
{
	int flag;

	flag = 0;

	str_rev(f_str_2, f_str_1);

	while ((*f_str_2++ != *f_str_1++)) {
		flag = 1;
		break;
	}

	return flag;
}
