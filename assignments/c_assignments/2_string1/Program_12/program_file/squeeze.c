/* Program to squeeze consecutive similar characters in string */

void str_squeeze(char *f_res_str, char *f_src_str)
{
	int i;

	for (i = 0; *(f_src_str+i) != '\0'; i++) {
		if ((*(f_src_str+i) != *(f_src_str+i+1))) {
			*(f_res_str++) = *(f_src_str+i);
		}
	}

	*f_res_str++ = '\0';
}
