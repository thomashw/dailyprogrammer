#include <stdlib.h>
#include <stdio.h>

#include "stack_string.h"

#define MAX_STRING_SIZE 80

/*int main(int argc, char *argv[])
{
	char *string = create_string();
	puts(string);
	push(string, 'c');
	push(string, 'a');
	push(string, 't');
	puts(string);
	pop(string);
	puts(string);
	clear(string);
	puts(string);
	set_base(string, "hey");
	puts(string);

	return 0;
}*/

char * create_string()
{
	char *new_string = (char*)malloc(sizeof(char)*MAX_STRING_SIZE);

	return new_string;
}

void set_base(char *string, char *new_base)
{
	while(*new_base != '\0')
	{
		*string++ = *new_base++;
	}
}

void push(char *string, char c)
{
	char *temp = string;

	while(*temp != '\0')
	{
		temp++;
	}

	*temp = c;
	*(++temp) = '\0';
}

void pop(char *string)
{
	char *temp = string;

	while(*temp != '\0')
	{
		temp++;
	}

	*(--temp) = '\0';
}

void clear(char *string)
{
	*string = '\0';
}
