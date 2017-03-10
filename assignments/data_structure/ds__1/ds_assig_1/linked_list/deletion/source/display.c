
#include "header.h"

void display(ST **head)
{

	ST *temp = *head;

	if(*head == NULL) {
		printf("\nlist is empty \n\n");
	}
	else {
		printf("displaying data\n");
		while(temp != NULL) {
			printf("%c->",temp->data);
			temp = temp->next;
		}
		printf("\n");
		printf("\n");
	}
}
	


