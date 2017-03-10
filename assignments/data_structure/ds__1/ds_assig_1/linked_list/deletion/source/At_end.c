
#include "header.h"

void at_end(ST **head)
{
	ST *temp = *head;
	ST *prev = NULL;

	if(temp == NULL) {
		printf("\n list is empty \n"); 
	}
	else if(nodes == 1) {
		*head = NULL; 
		}
	else {
		while((temp->next) != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
	}
	nodes--;
}



