
#include "header.h"

int at_penultimate_node(ST **head)
{
	int pos;
	int count = 1;	
	char poss[MAX];

	ST *new = (ST *)malloc(sizeof(ST));

	ST *temp = (ST *)malloc(sizeof(ST));

	temp = *head;

	
	printf("enter the data \n");
	fgets(&new->data, MAX, stdin);

	if(nodes == 1) {
		new->next = *head;
		*head = new;
		nodes++;
		return 0;
		}

	while(count != (nodes - 1)) {
		temp = temp->next;
		count++;
	}

	new->next = temp->next;
	temp->next = new;

	nodes++;
}
