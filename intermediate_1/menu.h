#ifndef MENU_H
#define MENU_H

typedef enum EventMenu
{
	EventMenuInvalid = 0,
	EventMenuAdd,
	EventMenuEdit,
	EventMenuDelete,
	EventMenuPrint,
	EventMenuQuit,
	EventMenuCount
} EventMenu;

void menu();

#endif
