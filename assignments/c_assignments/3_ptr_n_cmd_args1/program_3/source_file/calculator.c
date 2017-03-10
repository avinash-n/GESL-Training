/*
	Name: Calculator
	Author: Avinash N
	Date: 06 December 2016
	Description: This program implements a simple calculator
			with basic functions addition, subtraction,
			multiplication, division.
*/

#include "myheader.h"

int main(int argc, char *argv[])
{
	int num1;		/* Operand 1 */
	int num2;		/* Operand 2 */

	if (argc == 4) {
		num1 = my_atoi(argv[2]);
		num2 = my_atoi(argv[3]);

		if (!(strcmp(argv[1], "add"))) {
			fun_ptr = add;
		} else if (!(strcmp(argv[1], "sub"))) {
			fun_ptr = sub;
		} else if (!(strcmp(argv[1], "mul"))) {
			fun_ptr = mul;
		} else if (!(strcmp(argv[1], "_div"))) {
			fun_ptr = _div;
		} else {
			printf("Invalid input!\n");
			exit(1);
		}

		(*fun_ptr)(num1, num2);	/* Function call */
	} else {
		printf("Invalid input!\n");
		exit(1);
	}

	return 0;
}
