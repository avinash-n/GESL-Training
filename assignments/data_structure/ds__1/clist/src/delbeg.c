#include "header.h"

sl *delbeg(sl *head)
{
	sl *temp = NULL;
	temp = (sl *)malloc(sizeof(sl)*MAX);
	temp = head;
	while(temp -> next != head)
		temp = temp -> next;
		
	temp -> next = head -> next;
	head = head -> next;
	return head;
}
