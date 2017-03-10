/* this program is stack using arrays */

#include "header.h"

int main()
{

	char opp[MAX];
	char op;

	int top = -1;	
	int element;

	char elm[MAX];

	while(1) {

		printf("select the option perform on stack \n");
		printf("1.insert 2.deletion 3.display 4.exit \n");
		fgets(opp, MAX, stdin);
		op = *opp;

		switch(op) {

			case '1': printf("enter the element to insert\n");
					  fgets(elm, MAX, stdin);
					  *(elm + strlen(elm) - 1) = '\0';
					  element = atoi(elm);
					  push(element);
					  break;
			case '2': pop();
					  break;
			case '3': display();
					  break;
			case '4': exit(1);

			default : printf("enter the correct option \n");

		}
	}

	return 0;
}
