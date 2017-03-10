/*
	Name: Macros for bitwise operations
	Author: Avinash N
	Date:
*/

#include<stdio.h>
#include<stdlib.h>

#define max_num1 (((num2 - num1) >> (BIT_LENGTH - 1)) & 1) ? 1 : 0
#define max_num2 (((num1 - num2) >> (BIT_LENGTH - 1)) & 1) ? 1 : 0 
#define clear_right_most_set_bit (num & (num - 1))
#define clear_left_most_set_bit ()
#define set_bits ((num & mask(pos, bits)) | mask(pos, bits))
#define clear_bits (~((num & mask(pos, bits)) | mask(pos, bits)))
#define toggle_bits (num ^ mask(pos, bits))

int BIT_LENGTH = 8 * sizeof(void *);
extern int showbits(int);
extern int mask(int, int);

# if 1
int main()
{
	int num1;
	int num2;

	printf("Enter two numbers:");
	scanf("%d %d", &num1, &num2);

	if (max_num1) {
		printf("%d is greater than %d", num1, num2);
	} else if (max_num2) {
		printf("%d is greater than %d", num2, num1);
	} else {
		printf("Numbers are equal");
	}

	return 0;
}
# endif

# if 0
int main()
{
	unsigned int num;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Number after clearing right most set bit:\n");
	showbits(clear_right_most_set_bit);

	return 0;
}
# endif

# if 0
int main()
{
	unsigned int num;
	int s_pos;
	int d_pos;
	int pos;
	int bits;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Enter the position s:");
	scanf("%d", &s_pos);

	printf("Enter the position d:");
	scanf("%d", &d_pos);

	if (s_pos > d_pos) {
		pos = s_pos;
		bits = s_pos - d_pos + 1;
	} else {
		pos = d_pos;
		bits = d_pos - s_pos + 1;
	}

	printf("Number after setting bits:\n");
	showbits(set_bits);

	return 0;
}
# endif

# if 0
int main()
{
	unsigned int num;
	int s_pos;
	int d_pos;
	int pos;
	int bits;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Enter the position s:");
	scanf("%d", &s_pos);

	printf("Enter the position d:");
	scanf("%d", &d_pos);

	if (s_pos > d_pos) {
		pos = s_pos;
		bits = s_pos - d_pos + 1;
	} else {
		pos = d_pos;
		bits = d_pos - s_pos + 1;
	}

	printf("Number after clearing bits:\n");
	showbits(clear_bits);

	return 0;
}
# endif

# if 0
int main()
{
	unsigned int num;
	int s_pos;
	int d_pos;
	int pos;
	int bits;

	printf("Enter a number:");
	scanf("%d", &num);

	showbits(num);

	printf("Enter the position s:");
	scanf("%d", &s_pos);

	printf("Enter the position d:");
	scanf("%d", &d_pos);

	if (s_pos > d_pos) {
		pos = s_pos;
		bits = s_pos - d_pos + 1;
	} else {
		pos = d_pos;
		bits = d_pos - s_pos + 1;
	}

	printf("Number after toggling bits:\n");
	showbits(toggle_bits);

	return 0;
}
# endif
