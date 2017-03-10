#include"header.h"

int main()
{
	FILE *fp;
	char ch;

	if (NULL == (fp = fopen("question_1.txt", "w+"))) {
		perror("file pointer failed");
	}

	fprintf(fp,"THIS IS THE FIRST LINE OF CODE");
	rewind(fp);

	do{
		ch = fgetc(fp);
		if ((ch >= 'A') && (ch <= 'Z')) {
			ch = ch ^ 32;
		}
		fseek(fp, -1, SEEK_CUR);
		fputc(ch, fp);
	}while(ch != EOF);

	fclose(fp);
}
		
