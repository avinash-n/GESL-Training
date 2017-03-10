#include "header.h"

dll *delete_end(dll *head)
{
	dll *temp = NULL;
	temp = dms(temp);

	if ( head -> next == NULL ) {
		head = NULL;
		return head;
	}

	temp = head;

	while ( (temp -> next) -> next != NULL )
		temp = temp -> next;
	free(temp -> next);
	temp -> next = NULL;
	
	return head;
}
