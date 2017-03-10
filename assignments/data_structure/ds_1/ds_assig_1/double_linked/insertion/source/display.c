
#include "header.h"

void display(ST **head)
{
	ST *temp = *head;

	printf("displaying data\n");
	while(temp != NULL) {
		printf("%c->",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
	


