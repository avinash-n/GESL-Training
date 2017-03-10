/* This function returns the address of first occurance of a character
	in a given string */

int chr_addr(char *f_str, char *f_ch)
{
	int i;
	unsigned int flag;

	flag = 0;

	for (i = 0; *(f_str+i) != '\0'; i++) {
		if ((*(f_str+i)) == (*(f_ch))) {
			flag = f_str+i;
			break;
		} else {
			flag = 1;
		}
	}

	return flag;
}
