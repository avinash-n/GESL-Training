
#include "header.h"

int at_penultimate_node(ST **head)
{
	int count = 1;

	ST *temp = NULL;
	ST *prev = NULL;

	temp = *head;


	if(nodes == 1) {
		printf("\nthere is only one node in list \n");
		return 0;
	}
	if(nodes == 2) {
		while(count != nodes) {
			prev = temp;
			temp = temp->next;
			count++;
		}
		prev->next = temp->next;
		nodes--;
		return 0;
	}

	while(count != (nodes - 1)) {
		prev = temp;
		temp = temp->next;
		count++;
	}

	prev->next = temp->next;

	nodes--;
}
