
#include "header.h"

void display(int front, int rear, int queue[])                                  
{                                                                               
	int i;           

	if(rear == front)
		printf("queue is empty \n");

	else {

		for(i = front + 1; i <= rear; i++)                                              
			printf("elemnts %d\n",queue[i]);                                        
	}
}                                       
