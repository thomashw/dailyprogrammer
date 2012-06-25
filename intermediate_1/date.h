#ifndef DATE_H
#define DATE_H

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
