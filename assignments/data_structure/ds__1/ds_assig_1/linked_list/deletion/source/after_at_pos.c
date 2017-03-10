
#include "header.h"

int after_at_pos(ST **head)
{
	int pos;
	int count = 1;	
	char poss[MAX];
	ST *temp = NULL;
	ST *prev = NULL; 

	
	printf("enter the position to deletion after\n");
	fgets(poss, MAX, stdin);
	*(poss + strlen(poss) - 1) = '\0';

	pos = atoi(poss);

	if(((pos + 1) > (nodes + 1)) || ((pos + 1) <= 0)) {
		printf("enter the postion with in nodes \n");	
		return 0;
		}

	temp = *head;

	while((temp->next != NULL) && (count != (pos + 1))) {
		prev = temp;
		temp = temp->next;
		count++;
	}

	if((pos + 1) == 1) {
		*head = temp->next;
	}
	else {
		prev->next = temp->next;
	}
	nodes--;
}
