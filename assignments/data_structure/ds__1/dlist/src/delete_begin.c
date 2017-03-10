#include "header.h"

dll *delete_begin(dll *head)
{
	if ( head -> next == NULL ){
		free(head);
		head = NULL;
		return head;
	}
	head = head -> next;
	head -> previous = NULL;
	return head;
}
