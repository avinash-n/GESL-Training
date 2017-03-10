
#include "header.h"

int at_middle(ST **head)
{
	int count = 1;	
	
	ST *new = (ST *)malloc(sizeof(ST));

	ST *temp = NULL;

	temp = *head;

	if(temp == NULL) {
		printf("list is empty \n");
		return 0;
	}

	printf("enter the data \n");
	fgets(&new->data, MAX, stdin);

	if((nodes / 2) == 0) {
		new->next = *head;
		*head = new;
		new->prev = NULL;
		nodes++;
		return 0;
	}

	while(count != (nodes / 2)) {
		temp = temp->next;
		count++;
	}

	new->next = temp->next;
	temp->next = new;
	new->prev = temp;

	nodes++;
}
