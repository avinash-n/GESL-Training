/* C function definitions */

/* Conversion of case */
case_convert(char *str_ptr)
{
	char ch;

	while ((ch = fgetc(str_ptr)) != EOF ) {
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch ^ 32;
		}
	}
