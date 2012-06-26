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

typedef enum DateCompare {
	DateCompareLessThan = -1,
	DateCompareEqualTo = 0,
	DateCompareGreaterThan = 1
} DateCompare;

void init_date();
void add_date();
void remove_date(int key);
void print_dates();
void edit_date(int key);

#define INIT_DATE_CAPACITY 10

#endif
