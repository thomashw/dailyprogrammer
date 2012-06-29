#ifndef MENU_H
#define MENU_H

typedef enum
{
	StopWatchNone = -1,
	StopWatchStart,
	StopWatchRunning,
	StopWatchStop,
	StopWatchLap,
	StopWatchCount
} StopWatch;

void print_greeting();

#endif
