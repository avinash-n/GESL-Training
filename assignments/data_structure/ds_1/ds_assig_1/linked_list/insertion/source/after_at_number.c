/* after given number you can insert node */


#include "header.h"

int after_at_number(ST **head)
{
	char num;
	int count = 1;	

	
	printf("enter the data to insert after number\n");
	fgets(&num, MAX, stdin);

	ST *new = (ST *)malloc(sizeof(ST));
	
	if(new == NULL){
		printf("malloc failed to allocate memory \n");
		exit(1);
	}	

	ST *temp = NULL;

	temp = *head;

	while((temp->next != NULL) && (temp->data != num)) {
		temp = temp->next;
	}

	printf("enter the data \n");
	fgets(&new->data, MAX, stdin);

	if(temp->data == num) {
		new->next = temp->next;
		temp->next = new;
	}
	else {
		printf("the number not found \n");
		return 0;

	}
	nodes++;
}
