#include "header.h"

dll *insert_beg(dll *head) //insert at the begining
{
	dll *temp; //temporary pointer of type dll
	  
	dll *new; //pointer to create new node

	char *str; //string to take input from user

	int element; //element obtained from input

	str = dmc(str); //dynamic memory allocation of string
	
	temp = dms(temp); //dynamic memory allocation of structure pointer
	
	new = dms(new); //dynamic memory allocation of pointer
	
	temp = head; //storing head in temp
	
	printf("enter the element\n");
	str = get(str); //getting input by fputs
	element = atoi(str); //converting to integer from string
	
	if (temp == NULL ) { // if the list is empty add first node
		
		new -> data = element;
		new -> previous == NULL;
		new -> next = NULL;
		head = new;
		
	}
	
	else { //if the list is not empty

		new -> data = element;
		new -> previous = NULL;
		new -> next = temp;
		head -> previous = new;
		head = new;
		
	}
	return head; //return head to the called function
} 		
