#include<stdio.h>

const int i = 8*sizeof(int)-1;


extern unsigned int showbits(unsigned int num);
#define clear_right(num) \
for(r = 0; r <= 31 ; r++) {\
		if((( num >> r) & 1) == 1) {\
			num = num & (~(1 << r));\
			break;\
		} else {\
			continue;\
		}\
	}
			
#define clear_left(num)  \
for(r = 31; r >= 0 ; r--) {\
		if((( num >> r) & 1) == 1) {\
			num = num & (~(1 << r));\
			break;\
		} else {\
			continue;\
		}\
	}
#define set_right(num) \
for(r = 0; r<= 31 ; r++) {\
		if((( num >> r) & 1) == 0) {\
			num = num | (1 << r);\
			break;\
		} else {\
			continue;\
		}\
	}

#define set_left(num) \
for(r = 31; r >= 0 ; r--) {\
		if((( num >> r) & 1) == 0) {\
			num = num | (1 << r);\
			break;\
		} else {\
			continue;\
		}\
	}
#define toset(num, mask) ((mask & num) | mask); 
#define toclear(num, mask) ((( ~ mask) | num) & mask);
#define totoggle(num, mask) (mask ^ num);
#define max_min(num, num2)  \
temp = num ^ num2;\
if (temp ^ 1) {\
	printf("numbers are equal");\
	break;\
}\
for (j = 0; j <= i; j++); {\
	if (((temp << j) >> i) ^ 0) {\
		if ((((num << j) & (1 << i)) >> i) ^ 1) {\
			printf("number 2 is greater");\
		} else {\
			printf("number 1 is greater");\
		}\
	}\
}
			
				
	

main()
{
	int num;
	int num2;
	int s;
	int d;
	int mask;
	int c;
	int r = 0;
	int temp;
	int j;
	printf("Enter the number: ");
	scanf("%d", &num);

	showbits(num);

	printf("Enter the case from 1 to 8");
	scanf("%d", &c);
	
	switch(c) {
	case 1 : 
		printf("Enter the second number: ");
		scanf("%d", &num2);

		r = max_min(num, num2);
		if (r == 1)
			printf("number %d is maximum", num2);
		else if (r == 0)
			printf("number %d is greater", num);
		else 
			printf("number %d is greater", num2);
		break;
		

	case 2 :
		clear_right(num);
		printf("number after clearing the right set bit: %d\n",num );
	
		showbits(num);

		break;
	case 3 :
		clear_left(num);
		printf("number after clearing the leftmost set bit: %d\n", num);
	
		showbits(num);

		break;
	case 4 :
		set_right(num);
		printf("number after setting the right clear bit: %d\n", num);
	
		showbits(num);

		break;
	case 5 :
		set_left(num);
		printf("number after setting the left clear bit: %d\n", num);
	
		showbits(num);

		break;
	case 6:
		printf("Enter the source bit position");
		scanf("%d", &s);

		printf("Enter destination bit position ");
		scanf("%d", &d);

		mask = (( ~ ( (~ 0) << (s + 1- d))) << (s - 1));
 		r = toset(num, mask);

		printf("number after  set bit: %d\n", r);
	
		showbits(r);

		break;
	case 7 :
		printf("Enter the source bit position");
		scanf("%d", &s);

		printf("Enter destination bit position ");
		scanf("%d", &d);

		mask = (( ~ ( ~ 0 << (s + 1- d))) << (s - 1));
 		r = toclear(num, mask);

		printf("number after  clear bit: %d\n", r);
	
		showbits(r);

		break;
	case 8 :
		printf("Enter the source bit position");
		scanf("%d", &s);

		printf("Enter destination bit position ");
		scanf("%d", &d);

		mask = ( ~ ( ~ 0 << (s + 1- d))) << (s  - 1);
 		r = totoggle(num, mask);

		printf("number after  toggle bit: %d\n", r);
	
		showbits(r);

		break;
	}
}
