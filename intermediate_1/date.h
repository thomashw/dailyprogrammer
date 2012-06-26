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

void init_date();
void add_date();
void remove_date(int index);
void print_dates();

#define INIT_DATE_CAPACITY 10

#endif
