#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
#define limit 5

void push(int);
void pop(void);
void display();

int top;
int stack[limit];

#endif
