/* Function to find length of string */

#include "sort.h"

int str_len(char *f_str)
{
	int count;

	for (count = 0; *(f_str+count) != '\0'; count++) ;

	return (count - 1);
}
