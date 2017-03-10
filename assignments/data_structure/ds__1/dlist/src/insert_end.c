#include "header.h" //include header

dll *insert_end(dll *head) //function to insert at end
{
	dll *temp = NULL; //temporary pointer to traverse the list
	temp = dms(temp); //dynamic memory allocation of temp
	
	dll *new = NULL; //pointer of type dll to create new node
	new = dms(new); //dynamic memory allocation of new
	
	char *str = NULL; //string to get input from user 
	str = dmc(str); //dynamic memory allocation of str

	int element; //element the user asked to insert

	temp = head; //assigning head to temp
	
	printf("enter the element\n"); 
	str = get(str); //getting input from user
	element = atoi(str); //converting string to integer
	
	if ( temp == NULL ) { //if the list is empty insert at begining
		new -> data = element;
		new -> next = NULL;
		new -> previous = NULL;
		head = new;
		return head;
	}
		
		
	while ( temp -> next != NULL ) { //if the list is not empty insert at end
		temp = temp -> next;
	}
	
	new -> data = element;
	new -> next = NULL;
	new -> previous = temp;
	temp -> next = new;

	return head;
}
	
