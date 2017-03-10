
#include "header.h"

void enqueue(int element,int rear,int limit, int queue[])                       
{                                                                               
    if(rear >= limit)                                                           
        printf("queue is full \n");                                             
    else                                                                        
        queue[rear] = element;                                                  
}                     
