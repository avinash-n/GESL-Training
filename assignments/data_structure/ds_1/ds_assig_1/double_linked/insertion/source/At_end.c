
#include "header.h"

void at_end(ST **head)
{

	ST *new = (ST *)malloc(sizeof(ST));
	nodes++;
	new->next = NULL;
	
	printf("enter the data \n");
	fgets(&new->data, MAX, stdin);

	ST *temp = *head;

	if(temp == NULL) {
		new->next = *head;
		*head = new;
	 	new->prev = NULL;
		}
	else {
		while((temp->next) != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		}
}
	


