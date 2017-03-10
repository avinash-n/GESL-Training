/*
	This function copies entire source string
	into the destination string
*/

void string_copy(char *f_dst_str, char * f_src_str)
{
	while ((*f_dst_str++ = *f_src_str++))
	;

	*f_dst_str = '\0';
}
