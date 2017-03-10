#include<stdio.h>
#include<stdlib.h>

#define MAX 7 //length of satck
#define MIN -1 // minimum value of top of stack

int stack[MAX];

void push(int *);//function to push value to stack

void pop(int *);// pop the value from stack

void display(int *);// display the contents of stack
