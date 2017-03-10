#include "header.h"

dll *delete_mid(dll *head)
{
	if (head == NULL) {
		printf("List is empty\n");
		exit(0);
	} else {
		dll *temp = NULL;
		temp = dms(temp);
		int count = 1;
/*
//		dll *temp2 = NULL;
//		temp2 = dms(temp2);


		if ( head -> next == NULL ) {
			head  = NULL;
			return head;
		}
*/
		temp = head;

		while ( temp->next != NULL) {  
			count++;
			temp = temp -> next;
		}

//		printf ("%d-count\n",count);
		count = count/2;

		temp = head;

		while (count) {
			temp = temp -> next;
			count--;
		}

//		temp2 = temp -> next;

		temp -> previous -> next = temp -> next;
		temp -> next -> previous = temp -> previous;
		free(temp);

		//free(temp2);

		return head;
	} 
}
