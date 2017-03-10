#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef struct NODE                                                             
{                                                                               
    char data;                                                                  
    struct NODE *next;                                                          
}ST;     

ST *head; 
void delete_begin(ST **);
void display(ST **);
void at_end(ST **);
int at_pos(ST **);
int befre_at_pos(ST **);
int after_at_number(ST **);
int before_at_number(ST **);
int after_at_pos(ST **);
int at_middle(ST **);
int at_penultimate_node(ST **);

int nodes;
#endif
