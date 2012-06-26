#include "stdio.h"
#include "global.h"
#include "date.h"

static void increase_dates_size();
static void process_date(struct Date d);
static void sort_dates();

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
	dates[dates_size++] = d;
	sort_dates();
}

static DateCompare compare_dates(struct Date d1, struct Date d2)
{
	if(d1.year < d2.year)
		return DateCompareLessThan;
	if(d1.year > d2.year)
		return DateCompareGreaterThan;

	if(d1.month < d2.month)
		return DateCompareLessThan;
	if(d1.month > d2.month)
		return DateCompareGreaterThan;

	if(d1.day < d2.day)
		return DateCompareLessThan;
	if(d1.day > d2.day)
		return DateCompareGreaterThan;

	if(d1.hour < d2.hour)
		return DateCompareLessThan;
	if(d1.hour > d2.hour)
		return DateCompareGreaterThan;

	if(d1.minute < d2.minute)
		return DateCompareLessThan;
	if(d1.minute > d2.minute)
		return DateCompareGreaterThan;

	if(d1.second < d2.second)
		return DateCompareLessThan;
	if(d1.second > d2.second)
		return DateCompareGreaterThan;

	return DateCompareEqualTo;
}

static void sort_dates()
{
	int i, j;
	struct Date d;
	for(i = 0; i < dates_size-1; i++)
	{
		for(j = 0; j < dates_size-1; j++)
		{
			if(compare_dates(dates[j], dates[j+1]) == DateCompareGreaterThan)
			{
				d = dates[j+1];
				dates[j+1] = dates[j];
				dates[j] = d;
			}
		}
	}
}

void print_dates()
{
	int i;

	printf("\n\tYear\tMonth\tDay\tHour\tMinute\tSecond");

	for( i = 0; i < dates_size; i++ )
	{
		printf( "\n%d.\t%d",i+1, dates[i].year );
		printf( "\t%d",dates[i].month );
		printf( "\t%d",dates[i].day );
		printf( "\t%d",dates[i].hour );
		printf( "\t%d",dates[i].minute );
		printf( "\t%d",dates[i].second );
	}

	printf("\n");	
}

void remove_date(int key)
{
	struct Date temp;
	int i;

	key--;

	if(key < 0 || key > dates_size - 1)
	{
		printf("\nInvalid selection.");
		return;
	}

	for(i = key; i < dates_size-1; i++)
	{
		dates[i] = dates[i+1];
	}

	dates_size--;
}

void edit_date(int key)
{
	key--;

	struct Date d = read_date();

	if( validate_date( d ) )
	{
		dates[key] = d;
		sort_dates();
	}
}
