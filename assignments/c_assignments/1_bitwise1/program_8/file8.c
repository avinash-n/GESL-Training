/*
	Name: Write the following functions
		a. int cnt_leading_set_bits (int num)
			returns the number of leading set bits
		b. int cnt_leading_cleared_bits (int num)
			returns the number of leading cleared bits
		c. int cnt_trailing_cleared_bits (int num)
			returns the number of trailing cleared bits
		d. int cnt_trailing_set_bits (int num)
			returns the number of trailing set bits
	
	Author: Avinash N
	Date:
*/

#include<stdio.h>
#include<stdlib.h>

int cnt_leading_set_bits(int);
int cnt_leading_clear_bits(int);
int cnt_trailing_set_bits(int);
int cnt_trailing_clear_bits(int);

extern int showbits(int);

# if 1
int main()
{
	int num; //User Input : Number

	printf("\nEnter the number");
	scanf("%d",&num);

	if (num >= 0) {
		showbits(num);
		printf("\nCount:%d\n",cnt_leading_set_bits(num));
	} else {
		printf("Wrong Input");	
	}
	
	return 0;
}

int cnt_leading_set_bits(int f_num) //count leading set bits
{
	int i;
	int count;

	i = 0;
	count = 0;

	for(i = (8 * sizeof(void *)); i > 0 ; i--) {
		if (f_num & (1 << (i - 1))) {
			count++;
		} else {
			break;
		}
	} 
 
	return count;
	
}
#endif

# if 0
int main()
{
        int num; //User Input : Number

        printf("\nEnter the number");
        scanf("%d",&num);

        if(num >= 0){
                show_bit(num);
                printf("\n\nCount:%d",cnt_leading_clear_bits(num));
        }
        else
                printf("Wrong Input");  
                
}
int cnt_leading_clear_bits(int _num) //count leading clear bits
{
        int i = 0; //simple for loop variable
        int count = 0; //count clear bit
        for( i = (8 * sizeof(void *)); i > 0 ; i--){
                if(_num & (1 << (i-1)))
                        break;
                else
                        count++;
        } 
 
        return count;
        
}

#endif

# if 0
int main()
{
        int num; //User Input : Number

        printf("\nEnter the number");
        scanf("%d",&num);

        if(num >= 0){
                show_bit(num);
                printf("\nCount:%d\n",cnt_trailing_set_bits(num));
        }
        else
                printf("Wrong Input");  
                
}

int cnt_trailing_set_bits(int _num) //count trailing set bits
{
        int i = 0;
        int count = 0;
        for(i=0; i<(8 * sizeof(void *))-1; i++){
                if(_num & (1 << (i)))
                        count++;
                else
                        break;
        } 
 
        return count;
        
}

#endif

# if 0
int main()
{
        int num; //User Input : Number

        printf("\nEnter the number");
        scanf("%d",&num);

        if(num >= 0){
                show_bit(num);
                printf("Count:%d\n\n",cnt_trailing_clear_bits(num));
        }
        else
                printf("Wrong Input");  
                
}

int cnt_trailing_clear_bits(int _num) //count leading set bits
{
        int i = 0;
        int count = 0;
        for( i = (8 * sizeof(void *)); i > 0 ; i--){
                if(_num & (1 << (i-1)))
                        count++;
                else
                        break;
        } 
 
        return count;
        
}

#endif
