#include "header.h" //include header

int main(void) 
{
	dll *head = NULL; //starting node address
	char *str = NULL; //string to get input from user for option
	int option; //option variable to get option from user

	str = dmc(str); //dynamic memory allocation

	while (1) {
		printf("enter the option\n");
		printf("1.insert at begining\n");
		printf("2.insert at end\n");
		printf("3.insert at position\n");
		printf("4.delete at begining\n");
		printf("5.delete at end\n");
		printf("6.delete at middle\n");
		printf("7.display\n");

		str = get(str); //get input from user   
		option = atoi(str); //converting from string to integer

		switch (option) {
			case 1:
				head = insert_beg(head);
				break;
			case 2:
				head = insert_end(head);
				break;
			case 3:
				head = insertatpos(head);
				break;
			case 4: 
				if ( head == NULL ) {
					printf("the list is empty\n");
					break;
				}
				head = delete_begin(head);
				break;
			case 5:
				if ( head == NULL ) {
					printf("the list is empty\n");
					break;
				}
				head = delete_end(head);
				break;
			case 6:
				if ( head == NULL ) {
					printf("the list is empty\n");
					break;
				}
				head = delete_mid(head);
				break;
			case 7:
				display(head);
				break;
			default :
				printf("enter correct option\n");
		}
	}

	return 0;
}
