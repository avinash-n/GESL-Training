
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
		printf("3.inser_at_pos\n");
		printf("4.inser_befre_at_pos\n");
		printf("5.insert_after_at_pos\n");
		printf("6.insert_befre_at_number\n");
		printf("7.insert_after_at_number\n");
		printf("8.insert_at_MIDDLE\n");
		printf("9.insert_at_penultimate_node\n");
		printf("10.display\n");
		printf("11.exit\n");
	
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
					at_pos(&head);
					break;
			case 4: 
					befre_at_pos(&head);
					break;
			case 5: 
					after_at_pos(&head);
					break;
			case 6: 
					before_at_number(&head);
					break;
			case 7: 
					after_at_number(&head);
					break;
			case 8: 
					at_middle(&head);
					break;
			case 10: 
					display(&head);
					break;
			case 9:
					at_penultimate_node(&head); 
					break;
			case 11: 
					exit(1);
			default: printf("enter the correct option\n");
		}
	}
	return 0;
}
			
			
