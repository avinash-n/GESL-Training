#include "header.h"

dll *insertatpos(dll *head)
{
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
}
