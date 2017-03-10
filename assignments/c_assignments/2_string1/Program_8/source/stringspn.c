#include "header.h"

int stringspn(char *buf1, char *buf2)
{
	int i;
	int j;
	int count = 0;

	for (i = 0; *(buf1 + i) != '\0' ; i++) {
		for (j = 0; *(buf2 + j) != '\0'; j++) {
			if (*(buf1 + i) == *(buf2 + j)) {
				count++;
				break;
			} else {
				continue;
			}
		}
		if (*(buf2 + j) == '\0') {
			break;
		}
	}
	printf("%d\n",count);
	return count;
}
