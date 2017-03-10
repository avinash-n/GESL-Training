#include "header.h"

sl *delbeg(sl *head, sl *tail) {
	if (!(head)) {
		printf("List is empty\n");
		return NULL;
		exit(1);
	} else {
		sl *temp1 = NULL;
		sl *temp2 = NULL;
		temp1 = head;
		head = temp1 -> link;
		temp2 = tail;
		temp2 -> link = head;
		return head;
	}
}
