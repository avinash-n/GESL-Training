/*
	Name: Remove comments
	Aurhor: Avinash N
	Date: 06 December 2016
	Description: This program will remove the comments in a c file
			and write the modified file into another c file.
*/

#include "myheader.h"

int main(int argc, char *argv[])
{
	FILE *fp_src;			/* File handler for source file */
	FILE *fp_dst;			/* File handler for destination file */
	char ch;
	char ch_curr;			/* Currently read character */
	char ch_prev;			/* Previously read character */
	int flag;

	VALIDATE_ARGC;			/* Check if argc has sufficient input */

	fp_src = fopen(argv[1], "r");
	VALIDATE_FP(fp_src);			/* Validate source file handler */

	fp_dst = fopen(argv[2], "w");
	VALIDATE_FP(fp_dst);			/* Validate destination file handler */

	ch_curr = fgetc(fp_src);
	while ((ch = fgetc(fp_src)) != EOF) {
		ch_prev = ch_curr;
		ch_curr = ch;
		flag = 1;

		if ((ch_prev == '/') && (ch_curr == '/')) {
			while (flag) {
				ch_prev = ch_curr;
				ch_curr = fgetc(fp_src);
				if ((ch_curr == '\n')) {
					flag = 0;
				}
			}
		} else if ((ch_prev == '/') && (ch_curr == '*')) {
			while (flag) {
				ch_prev = ch_curr;
				ch_curr = fgetc(fp_src);
				if (((ch_prev == '*') && (ch_curr == '/'))) {
					flag = 0;
				}
			}
			ch_curr = fgetc(fp_src);
		} else {
			fputc(ch_prev, fp_dst);
		}
	}

	fclose(fp_src);			/* Close source file */
	fclose(fp_dst);			/* Close destination file */

	return 0;
}
