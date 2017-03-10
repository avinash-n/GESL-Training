
#include "header.h"

int dequeue(int element, int front, int rear, int queue[])                      
{                                                                               
    if((front == -1) || (front > rear))                                         
        printf("queue is empty \n");                                            
    else                                                                        
        element = queue[front];                                                 
                                                                                
    return element;                                                             
}                             
