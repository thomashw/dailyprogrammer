#include "stdio.h"
#include "global.h"
#include "menu.h"
#include "date.h"

static void respond_to_selection(EventMenu t);
static void say_hello();
static void exit_app();

void menu()
{
	static bool hello_shown = false;
	char c[100];
	EventMenu t = EventMenuInvalid;

	if( hello_shown == false )
	{
		say_hello();
		hello_shown = true;
	}

	printf("\nPlease select from the following options.");
	printf("\n\n1. Add event");
	printf("\n2. Edit event");
	printf("\n3. Delete event");
	printf("\n4. Print events");
	printf("\n5. Quit\n");

	fgets(c, sizeof(c), stdin);
	sscanf(c, "%d", &t);

	respond_to_selection(t);
}

static void respond_to_selection(EventMenu t)
{
	switch(t)
	{
		case EventMenuAdd:
			add_date();
			break;
		case EventMenuEdit:
			break;
		case EventMenuDelete:
			break;
		case EventMenuPrint:
			print_dates();
			break;
		case EventMenuQuit:
			exit_app();
			break;
		default:
			printf("\nInvalid selection.");
	}
}

static void say_hello()
{
	printf("\n\nWelcome to your event organizer!\n\n");
}

static void exit_app()
{
	printf("\nBye!");
	exit(0);
}
