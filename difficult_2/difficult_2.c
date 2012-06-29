/*
Created by: Thomas Hewton-Waters
reddit.com/r/dailyprogrammer

Your mission is to create a stopwatch program. 
this program should have start, stop, and lap 
options, and it should write out to a file to 
be viewed later.
*/

#include <time.h>
#include <stdio.h>
#include "menu.h"

int main(int argc, char* argv[])
{
	print_greeting();

	while(1)
	{
		menu();
	}

	return 0;
}
