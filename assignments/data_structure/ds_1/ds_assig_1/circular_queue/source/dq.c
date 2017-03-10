#include "header.h"

void dequeue(int queue[])
{
        int element;
        
	if((count == 0 ))
        {
                printf("queue empty\n");
        }
        else
        {
		count--;
		f =f%limit;
                element = queue[f];
                printf("enqued:%d\n",element);
                f++;
        }
}
