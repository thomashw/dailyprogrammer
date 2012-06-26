#include "stdio.h"
#include "global.h"
#include "date.h"

static void increase_dates_size();
static void process_date(struct Date d);

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

	if( validate_date( d ) )
	{
		if(dates_size > (dates_capacity - 1))
		{
			increase_dates_size();
		}

		process_date(d);
	}
}

static void increase_dates_size()
{
	struct Date *temp = (struct Date*)realloc(dates, dates_capacity * 2 * sizeof(struct Date));

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

static void process_date(struct Date d)
{
	if( dates_size == 0 )
	{
		dates[dates_size++] = d;
	}
	else
	{
		int index = 0;
		struct Date temp = dates[index];

		while(((d.year > temp.year) ||
			(d.year == temp.year && d.month > temp.month) ||
			(d.year == temp.year && d.month == temp.month && d.day > temp.day) ||
			(d.year == temp.year && d.month == temp.month && d.day == temp.day && d.hour > temp.hour) ||
			(d.year == temp.year && d.month == temp.month && d.day == temp.day && d.hour == temp.hour && d.minute > temp.minute) ||
			(d.year == temp.year && d.month == temp.month && d.day == temp.day && d.hour == temp.hour && d.minute == temp.minute && d.second == temp.second)) &&
			index < dates_size)
		{
			temp = dates[++index];
		}
		
		int i;
		for(i = dates_size; i > index; i--)
		{
			dates[i] = dates[i-1];
		}

		dates[index] = d;
		dates_size++;
	}
}

void print_dates()
{
	int i;

	printf("\nYear\tMonth\tDay\tHour\tMinute\tSecond");

	for( i = 0; i < dates_size; i++ )
	{
		printf( "\n%d", dates[i].year );
		printf( "\t%d", dates[i].month );
		printf( "\t%d", dates[i].day );
		printf( "\t%d", dates[i].hour );
		printf( "\t%d", dates[i].minute );
		printf( "\t%d", dates[i].second );
	}
}
