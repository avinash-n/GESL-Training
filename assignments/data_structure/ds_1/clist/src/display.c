#include "header.h" //include header file                                       
                                                                                
void display(sl *head) //display function to show elements in list              
{                                                                               
    sl *temp = NULL; //declaring temporary pointer to structure sl              
    temp = (sl *)malloc(sizeof(sl)*MAX); //dynamic memory allocation            
    temp = head; //assigning head to the temp                                   
                                                                                
    if ( temp == NULL ) // traversing through the list                          
        printf("no elements in the list\n");                                    
    else {    
        printf("the elements in the list are\n");                               
    while ((temp -> next) != head) { //traversing through the list                        
        printf("%d\t",temp -> data);                                            
        temp = temp -> next;                                                    
    }
		printf("%d",temp -> data);                                                                           
    	printf("\n");                                                               
    }                                                                           
}  
