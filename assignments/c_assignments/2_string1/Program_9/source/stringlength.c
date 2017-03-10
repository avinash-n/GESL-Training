#include"header.h"

int stringlength(char *str)
{
	int count = 0;

	while(*str++ != '\0') {
		count++;
	}
	printf("count is %d\n ", count);
	return count;
}
