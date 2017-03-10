#include "header.h"

void deletion_begin(ST **head)
{

	ST *temp;

	temp = *head;
	
	*head = temp->next;

	nodes--;

}
		
