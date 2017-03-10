#include"header.h"

void substring(char *str, char *sstr)
{ 
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;
	char *str1;
	str1 = (char *) malloc(sizeof(char)*MAX);

	while(*(str + i) != '\n') {
		for(k = 0; k < stringlength(sstr) - 1; k++) {
			if(*(str + i + k) == *(sstr + k)) {
				count++;
			} 
		}
		if (count == (stringlength(sstr) - 1)) {
			i = i + count -1;		
		} else {
			*(str + j) = *(str + i);
			j++;
		}
		count = 0;
		i++;
	}
	*(str + j) = '\0';
}
							
		
