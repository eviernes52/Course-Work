#include "Calendar.h"
#include "Table.h"
#include "Attributes.h"
#include "Clubs.h"

Calendar::Calendar()
{
	time_t raw_time;
	time(&raw_time); //returns the time since the Epoch (00:00:00 UTC, January 1, 1970), measured in seconds.

	struct tm *my_date = localtime(&raw_time); //struct tm - this is a structure used to hold the time and date.


	year = my_date->tm_year + 1900; //The number of years since 1900
	month = my_date->tm_mon + 1; //Month, range 0 to 11. Adding +1 for better readability.
	day_of_a_month = my_date->tm_mday;
	day_of_a_week = my_date->tm_wday;
	hour = my_date->tm_hour;
	minute = my_date->tm_min;
	seconde = my_date->tm_sec;
}

void Calendar::Set_Hour() //Used by History class to save messages - it update's the time, without updating the date, because date is constantly modified by Travel_Calendar().
{
	time_t raw_time;
	time(&raw_time); //returns the time since the Epoch (00:00:00 UTC, January 1, 1970), measured in seconds.

	struct tm *my_date = localtime(&raw_time); //struct tm - this is a structure used to hold the time and date.

	if (my_date->tm_hour < hour) //For example if we had 23:00 in-game. 2 hours later user decided to use this function, it means it's 01:00. That's why we need to increment days.
		Travel_Calendar(1);

	hour = my_date->tm_hour;
	minute = my_date->tm_min;
	seconde = my_date->tm_sec;
}


void Calendar::Print_Date() const
{
	printf ("Todays date: %d.%d.%d\n\t     %d:%d:%d\n", day_of_a_month, month, year,
			hour, minute, seconde);
}

void Calendar::Travel_Calendar(int days)
{
	if(day_of_a_month + days > 31) //because there can't be 32th day of a month (or more)
	{
		if(month == 12)
		{
			++year;
			month = 1;

			for(unsigned int i = 0; i < tables.size(); ++i) //for every table (league)
				for(int a = 0; a < tables[i]->number_of_clubs; ++a) //for every club in a table
					tables[i]->clubs[a]->Year_Passed(); //Making clubs aware that it is a New Year.
		}
		else
			++month;

		day_of_a_month += days;
		day_of_a_month = day_of_a_month - 31; //For example: 31 December and we want to travel 7 days. It will give us 7 January.
	}
	else
		day_of_a_month += days;

	Set_Hour();
}




Calendar& Calendar::get()
{
	static Calendar calendar;
	return calendar;
}

Calendar::~Calendar()
{

}

void Calendar::Add_Table(Table &table)
{
	tables.push_back(&table);
}
