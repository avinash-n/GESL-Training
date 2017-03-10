#include<stdio.h>

extern int showbit(int );  //extern function showbits() from file showbit.c

int cnt_leading_set_bits(int );
int cnt_leading_cleared_bits(int );
int cnt_trailing_cleared_bits(int );
int cnt_trailing_set_bits(int );

//function to count the number of 1's at leading end
int cnt_leading_set_bits(int num)
{
	int i;
	int cnt = 0;
	
	for (i = 31; (i >= 0) && ((num >> i) & 1); i--) {
			cnt++;        //increment count
			}
	return cnt;
}


//function to count the number of 0's at leading end
int cnt_leading_cleared_bits(int num)
{
	int i;
	int cnt = 0;

	for (i = 31; (i >= 0) && ((~(num >> i)) & 1)  ; i--) {
			cnt++;           //increment count
		}
	return cnt;
}


//function to count number of 0's at trailing end
int cnt_trailing_cleared_bits(int num)
{
	int i;
	int cnt = 0;

	for (i = 0; (i <= 31) && ((~(num >> i) & 1)); i++) {
			cnt++;          //increment count;
	}
	return cnt;
}


//function to count number of 1's at trailing end
int cnt_trailing_set_bits(int num)
{
	int i;
	int cnt = 0;

	for (i = 0; (i <= 31) && (num >> i) & 1; i++) {
				cnt++;           //increment count
	}
	return cnt;
}

int main(void)
{
	int num;               //number taken as input

	printf("Enter a number to count the number of leading or trailing bits\n");
	scanf("%d", &num);

	showbit(num);

	printf(" No. of leading set bits: %d\n", cnt_leading_set_bits(num));
	printf("No. of leading clear bits: %d\n", cnt_leading_cleared_bits(num));
	printf("No. of trailing clear bits: %d\n", cnt_trailing_cleared_bits(num));
	printf("No. of trailing set bits are %d\n", cnt_trailing_set_bits(num));

	return 0;
}

