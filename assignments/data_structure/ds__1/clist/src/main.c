#include "header.h"                                                             
                                                                                
int main()                                                                      
{                                                                                                                                    
    sl *head = NULL;                                                            
    int option;                                                                 
    char *str = NULL;                                                                  
//    head = (sl *)malloc(sizeof(sl)*MAX);                                                                            
    str = (char *)malloc(sizeof(char)*MAX);                                     
                                                                               
    while (1) {                                                                 
                                                                                
        printf("enter 1 for insertion\nenter 2 for deletion\n");                
        printf("enter 3 for display\nenter 4 for exit\n");                      
                                                                                
        fgets(str,MAX,stdin);                                                   
        option = atoi(str);                                                     
                                                                                
        switch(option) {                                                        
                                                                                
        case 1:
                    head = insert(head); 
                    break;                                                      
        case 2:                                                                 
                    if ( head == NULL ) {                                       
                        printf("there are no elements in list to delete\n");    
                        break;                                                  
                    }                                                           
                    else {                                                      
                        head = delbeg(head);                                       
                        break;                                                  
                    }                                                           
        case 3:                                                                 
                    display(head);                                              
                    break;                                                      
        case 4:                                                                 
                    return 0;                                                   
        default :                                                               
                    printf("enter the correct option\n");        
	
		}
	}
}
