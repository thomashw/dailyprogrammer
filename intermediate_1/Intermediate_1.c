/*
create a program that will allow you to enter events 
organizable by hour. There must be menu options of 
some form, and you must be able to easily edit, add, 
and delete events without directly changing the source code.
(note that by menu i dont necessarily mean gui. 
as long as you can easily access the different options 
and receive prompts and instructions telling you how 
to use the program, it will probably be fine)
*/

#include "Intermediate_1.h"
#include "Date.h"

int main( int argc, char* argv )
{
	while( 1 )
	{
		add_date();
		print_dates();
	}

	return 0;
}
