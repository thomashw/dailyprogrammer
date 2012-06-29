#include <stdio.h>
#include "menu.h"

#define COMMAND_START "START\n"
#define COMMAND_STOP "STOP\n"
#define COMMAND_LAP "LAP\n"

typedef enum
{
	CommandStart = 0,
	CommandStop,
	CommandLap,
	CommandCount
} Command;

static void readCommand();

void print_greeting()
{
	printf("\n\nWelcome to your stopwatch.\n");
}

void menu()
{
	printf("\n\nCommands:");
	printf("\nSTART\t:\tstart the stopwatch");
	printf("\nSTOP\t:\tstop the stopwatch");
	printf("\nLAP\t:\tprint the lap timer");
	printf("\nq\t:\tquit");
	printf("\n\n");

	readCommand();
}

static void readCommand()
{
	char c[100];

	fgets(c, sizeof(c), stdin);

	if(strcmp(COMMAND_START, c) == 0)
	{
		printf("\nStarting.");
	}
	else if(strcmp(COMMAND_STOP, c) == 0)
	{
		printf("\nStopping.");
	}
	else if(strcmp(COMMAND_LAP, c) == 0)
	{
		printf("\nLap.");
	}
	else if(c[0] == 'q')
	{
		printf("\nBye!");
		exit(0);
	}
}
