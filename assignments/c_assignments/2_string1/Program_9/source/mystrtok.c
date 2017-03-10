#include"header.h"

void mystrtok(char *str, char *delim)
{
	int i;
	int j;

	for(i = 0; *(str + i) != '\0'; i++) {
		for(j = 0; *(delim +j) != '\0'; j++) {
			if (*(str + i) == *(delim + j)) {
				
				break;
			} else {
				continue;
			}
		}
		if(*(str + i) == '\0') {
			break;
		}
	}
}
