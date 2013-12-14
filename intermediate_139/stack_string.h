#ifndef STACK_STRING
#define STACK_STRING

char * create_string();
void push(char *string, char c);
void pop(char *string);
void set_base(char *string, char *new_base);
void clear(char *string);

#endif