/* Definition of basic calculator functions */

#include "myheader.h"

void add(int f_num1, int f_num2)
{
	printf("%d + %d  = %d\n", f_num1, f_num2, (f_num1 + f_num2));
}

void sub(int f_num1, int f_num2)
{
	printf("%d - %d = %d\n", f_num1, f_num2, (f_num1 - f_num2));
}

void mul(int f_num1, int f_num2)
{
	printf("%d * %d = %d\n", f_num1, f_num2, (f_num1 * f_num2));
}

void _div(int f_num1, int f_num2)
{
	printf("%d / %d = %d\n", f_num1, f_num2, (f_num1 / f_num2));
}
