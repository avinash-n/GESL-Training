#include"header.h"

void insert(char *str, char *ch, int pos)
{
	int i;
	int n = stringlength(str) - 1;
	
	for(i = (n - 1); i >= (pos - 1); i--) {
		*(str + ( i + 1)) = *(str + i);
	}
	*(str + (pos - 1)) = *(ch + 0);
	printf("str : %s\n", str);
} 
