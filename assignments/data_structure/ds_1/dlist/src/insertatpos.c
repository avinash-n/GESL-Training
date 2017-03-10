#include "header.h"

void *insertatpos(dll *head, dll *insert_node, int pos) {
	if (!(head)) {
		printf("List is empty\n");
		exit(0);
	} else {
		dll *temp = NULL;
		int count = 2;
		temp = head;

		if (pos ==1) {
			insert_node -> next = head;
			temp -> previous = insert_node;
		} else {
			while (pos != count) {
				if (temp -> next) != NULL) {
					temp = temp -> next;
					count++;
				} else if (count < pos) {
					printf("Position out of list\n");
					break;
				}
			}
			temp -> previous -> next = insert_node;
			insert_node -> previous = temp -> previous;
			insert_node -> next = temp;
			temp -> previous = insert_node;
		}
	}
					
/*
	dll *temp = NULL;
	temp = dms(temp);
	
	dll *new = NULL;
	new = dms(new);
	int element;
	int position;
	int i = 0;
	char *str = NULL;
	str = (char *)malloc(sizeof(char)*MAX);
	printf("enter the position\n");
	fgets(str,MAX,stdin);
	position = atoi(str);
	temp = head;
	while(temp != NULL ){
	temp = temp -> next;
	i++;
	}
	if(position > i){
	printf("position not available\n");
	return head;
	}
	temp = head;
	printf("enter the element\n");
	fgets(str,MAX,stdin);
	element = atoi(str);
	while(--position) 
		temp = temp -> next;
	new -> data = element;
	new -> next = temp;
	new -> previous = temp -> previous;
	temp -> previous = new;
	if (new -> previous == NULL)
	head = new;
	return head;
*/
}
