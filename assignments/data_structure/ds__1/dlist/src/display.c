#include "header.h"

void display(dll *head)
{
	if(head == NULL) {
		printf("no elements in list\n");
		exit(0);
	} else {
		dll *temp;
		temp = dms(temp);
		temp = head;
		printf("the elements in list are\n");

		while ( temp ->next != NULL ){
			temp = temp -> next;

		}
		while (temp != NULL) {
			printf("%d\t",temp -> data);
			temp = temp -> previous;
		}

		printf("\n");
	}
}
