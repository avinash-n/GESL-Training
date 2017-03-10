/*
	Name: Implementing strtok()
	Author: Avinash N
	Date: 24 November 2016
	Description: 
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char  *str;
	char  *delim;
	
	str = (char *) malloc(sizeof(char)*MAX);
	delim = (char *) malloc(sizeof(char)*MAX);
	
	printf("Enter the string : \n");
	fgets(str, MAX, stdin);

	printf("enter the delimiter : \n");
	fgets(delim, MAX, stdin);

	mystrtok(str, delim);

	printf("the string is %s \n", str); 

	free(str);	
	free(delim);
	return 0;
}
