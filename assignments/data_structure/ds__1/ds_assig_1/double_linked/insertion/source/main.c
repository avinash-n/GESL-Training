
#include "header.h"

int main()
{

	head = NULL;
	char op[MAX];
	int opp;
	char ch;

	printf("creating nodes \n");
	do {
		creat_node(&head);
		printf("you want another node \n");
		fgets(&ch, MAX, stdin);
		}while(ch == 'y' || ch == 'Y');
	
	while(1) {

		printf("enter the option \n");
		printf("1.insert_begin\n");
		printf("2.insert_end\n");
		printf("3.insert_at_MIDDLE\n");
		printf("4.display\n");
		printf("5.exit\n");
	
		fgets(op, MAX, stdin);
		*(op + strlen(op) - 1) = '\0';

		opp = atoi(op);
		
		switch(opp) {
				
			case 1: 
					insert_begin(&head);
					break;
			case 2:
					at_end(&head);
					break;
			case 3: 
					at_middle(&head);
					break;
			case 4:
					display(&head);
					break;
			case 5: 
					exit(1);
			default: printf("enter the correct option\n");
		}
	}
	return 0;
}
			
			
