/*
	Name: Single Linked List
	Author: Avinash N
	Date: 05 December 2016
	Description: This program will perform following operations
			on Single Linked List.
			1. Insert at the beginning
			2. Insert at the end
			3. Insert at a given position
			4. Insert before a given position
			5. Insert after a given position
			6. Insert before a given number
			7. Insert after a given number
			8. Insert at the middle
			9. Insert at penultimate node
*/

#include "myheder.h"

int main(void)
{
	char *opt;
	int option;

	MEM_ALLOC(opt);
	VALIDATE_MALLOC(opt);

	printf("----DOUBLE LINKED LIST----\N");

	do {
		printf("Operations available:\n");
		printf("1. Insert at the beginning\n
			2. Insert at the end\n
			3. Insert at a given position\n
			4. Insert before a given position\n
			5. Insert after a given position\n
			6. Insert before a given number\n
			7. Insert after a given number\n
			8. Insert at the middle\n
			9. Insert at penultimate node\n");
		printf("Select the operation: ");
		fgets(opt, NUM_SIZE, stdin);

		option = validate(opt);

		switch(option) {
		case 1:
			insert_1();
			break;
		case 2:
			insert_2();
			break;
		case 3:
			insert_3();
			break;
		case 4:
			insert_4();
			break;
		case 5:
			insert_5();
			break;
		case 6:
			insert_6();
			break;
		case 7:
			insert_7();
			break;
		case 8:
			insert_8();
			break;
		case 9:
			insert_9();
			break;
		case 10:
			display();
			break;
		case 11:
			printf("Linked list is released:\n");
			exit(0);
		default:
			printf("***Enter the valid option***");
			break;
		}
	} while (1);

	return 0;
}
