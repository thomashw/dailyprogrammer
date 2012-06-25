#ifndef DATE_H
#define DATE_H

typedef enum {
	false = 0,
	true = 1
} bool;

struct Date {
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int second;
};

void add_date();
void print_dates();

#endif
