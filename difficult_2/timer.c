#include <time.h>
#include "menu.h"

StopWatch command = StopWatchNone;

void sm_stopwatch()
{
	static time_t base_time;
	time_t elapsed_time;

	switch(command)
	{
		case StopWatchNone:
			break;
		case StopWatchStart:
			base_time = time(NULL);
			command = StopWatchRunning;
			break;
		case StopWatchRunning:
			elapsed_time = time(NULL) - base_time;
			break;
		case StopWatchStop:
			break;
		case StopWatchLap:
			break;
		default:
			command = StopWatchNone;
	}
}
