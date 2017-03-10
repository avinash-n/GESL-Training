#include"header.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	char *str;
	char *words;
	int l_c = 0;
	int i = 0;
	int j = 0;

	
	if (NULL == (str = (char *) malloc(sizeof(char)*MAX))) {
		perror("malloc failed");
	}
	if (NULL == (words = (char *) malloc(sizeof(char)*MAX))) {
		perror("malloc failed");
	}
	
	if ( NULL == (fp = fopen(argv[1], "r"))) {
		perror(argv[1]);
	}
	while(NULL != (fgets(str, MAX, fp))) {
		l_c++;
		*(str + strlen(str) - 1) = '\0';
		while(*(str + i) != '\0') {
			while((*(str + i) != ' ') && *(str + i)) {
				*(words + j) = *(str + i) ;
				i++;
				j++;
			}
			*(words + j) = '\0';
			if(strcmp(argv[2], words) == 0) {
				printf("line number is : %d", l_c);
				printf("line is: %s", str);
				break;
			}
			j = 0;
			i++;
		}
		i = 0;
	}
	fclose(fp);
}	
