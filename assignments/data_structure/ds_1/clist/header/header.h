#include <stdio.h> //include header file

#include <stdlib.h> //include standard library

#define MAX 64 //macro to define MAX

typedef struct list {  //structure to define list                                                         
    int data;   //integer data in list                                                                
    struct list *next; //pointer to hold address of next element                                                         
}sl;

sl *insert(sl *head);
sl *deleteend(sl *head);
void display(sl *head);
sl *delbeg(sl *head);
