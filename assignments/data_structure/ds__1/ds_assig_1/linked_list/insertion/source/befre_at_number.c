/* after given number you can insert node */


#include "header.h"

int before_at_number(ST **head)
{
	char num;
	int count = 1;	

	
	printf("enter the data to insert before number\n");
	fgets(&num, MAX, stdin);

	ST *new = (ST *)malloc(sizeof(ST));

	ST *temp = NULL;
	ST *prev = NULL;
	
	temp = *head;
	
	printf("enter the data \n");
	fgets(&new->data, MAX, stdin);

	if(temp->data == num) {
		new->next = *head;
		*head = new;
		nodes++;
		return 0;
	}
	

	while((temp->next != NULL) && (temp->data != num)) {
		prev = temp;
		temp = temp->next;

	}

	if(temp->data == num) {
		prev->next = new;
		new->next = temp;
	}
	else {
		printf("the number not found \n");
		return 0;

	}
	nodes++;
}
