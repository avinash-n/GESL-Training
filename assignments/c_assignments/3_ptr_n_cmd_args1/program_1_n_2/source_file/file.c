/*
	Name: Function pointer and command line arguments.
	Author: Avinash N
	Date: 25 November 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# if 1
/*
 * This program displays the number of files in a folder
 * using command line arguments.
 */

int main(int argc, char *argv[])
{
	printf("Number of files in the given directory is: %d\n", (argc - 1));

	return 0;
}

# endif

# if 0
int main(int argc, char *argv[])
{
	int count_c;			/* Counter for c files */
	int count_txt;			/* Counter for text files */
	int count_other;		/* Counter for other files */
	int total;			/* Total number of files in directory */

	count_c = 0;
	count_txt = 0;
	count_other = 0;
	total = (argc - 1);

	for (; argc > 1; argc--) {
		if (!(strstr(argv[argc], ".c"))) {
			count_c++;
		} else if (!(strstr(argv[argc], ".txt"))) {
			count_txt++;
		} else {
			count_other++;
		}
	}

	printf("In the given directory:-\n");
	printf("Number of '.c' files  : %d\n", count_c);
	printf("Number of '.txt' files: %d\n", count_txt);
	printf("Number of other files : %d\n", count_other);
	printf("Total number of files : %d\n", total);
	return 0;
}
# endif
