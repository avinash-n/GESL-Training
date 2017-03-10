#include "header.h"

void display(int queue[])
{
        int x= f;
	int copy = count;
        int element;
        
	if((count==0 ))
        {
                printf("empty\n");
        }
        else
        { printf("elements are:\n");
        while(copy){
		copy--;
		x = x%limit;
                element = queue[x];
                printf("queue[%d]:%d\n",x,element);
                x++;}
        }
}

