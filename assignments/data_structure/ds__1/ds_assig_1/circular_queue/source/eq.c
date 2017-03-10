#include "header.h"

void enqueue(int element)
{
        if(count >= limit)
        {
                printf("queue full\n");
        }
        else
        {	
		count++;
                r++;
		r = r % limit;
                queue[r] = element;
        }
}


