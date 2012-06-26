#include "stdio.h"
#include "global.h"
#include "date.h"

struct Date* dates;
int dates_size = 0;
int dates_capacity = 0;

void init_date()
{
	dates = (struct Date*)calloc( INIT_DATE_CAPACITY, sizeof(struct Date));
	dates_capacity = INIT_DATE_CAPACITY;
	dates_size = 0;
}

static struct Date new_date( int day, int month, int year, int hour, int minute, int second )
{
	struct Date d;
	d.day = day;
	d.month = month;
	d.year = year;
	d.hour = hour;
	d.minute = minute;
	d.second = second;

	return d;
}

static bool validate_date( struct Date d )
{
	bool valid = true;

	if( d.day < 1 || d.day > 31 )
	{
		printf("\nInvalid day.");
		valid = false;
	}

	if( d.month < 1 || d.month > 12 )
	{
		printf("\nInvalid month.");
		valid = false;
	}

	if( d.hour < 0 || d.hour > 23 )
	{
		printf("\nInvalid hour.");
		valid = false;
	}

	if( d.minute < 0 || d.minute > 59 )
	{
		printf("\nInvalid minute.");
		valid = false;
	}

	if( d.second < 0 || d.second > 59 )
	{
		printf("\nInvalid second.");
		valid = false;
	}

	if( valid == false )
		printf("\nNot adding date. Invalid data.");

	return valid;
}

static struct Date read_date()
{
	char c[100];
	struct Date d;

	printf("\nEnter the following information.");

	printf("\nDay: ");
	fgets(c, sizeof(c), stdin);
	sscanf(c, "%d", &d.day);

	printf("Month: ");
	fgets(c, sizeof(c), stdin);
	sscanf(c, "%d", &d.month);

	printf("Year: ");
	fgets(c, sizeof(c), stdin);
	sscanf(c, "%d", &d.year);

	printf("Hour: ");
	fgets(c, sizeof(c), stdin);
	sscanf(c, "%d", &d.hour);

	printf("Minute: ");
	fgets(c, sizeof(c), stdin);
	sscanf(c, "%d", &d.minute);

	printf("Second: ");
	fgets(c, sizeof(c), stdin);
	sscanf(c, "%d", &d.second);

	return d;
}

void add_date()
{
	struct Date d = read_date();
	struct Date *temp;

	if( validate_date( d ) ) {
		if(dates_size > (dates_capacity - 1))
		{
			temp = (struct Date*)realloc(dates, dates_capacity * 2 * sizeof(struct Date));

			if(temp != NULL)
			{
				dates = temp;
				dates_capacity *= 2;
			}
			else
			{
				free(dates);
				printf("\nError reallocating memory.");
				exit(1);
			}
		}

		dates[dates_size++] = d;
	}
}

void print_dates()
{
	int i;

	for( i = 0; i < dates_size; i++ )
	{
		printf( "\nDay: \t%d", dates[i].day );
		printf( "\nMonth: \t%d", dates[i].month );
		printf( "\nYear: \t%d", dates[i].year );
		printf( "\nHour: \t%d", dates[i].hour );
		printf( "\nMin: \t%d", dates[i].minute );
		printf( "\nSec: \t%d\n", dates[i].second );
	}
}
