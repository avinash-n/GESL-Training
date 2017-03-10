int stringlength(char *scr)
{
	int count = 0;	

	while(*scr != '\0') {
		count++;
		scr++;
	}
	return count;
}
