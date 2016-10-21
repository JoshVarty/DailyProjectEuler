// 2016.10.14.Problem19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Date {
	int year;
	int month;			//1 = Jan
	int day;			//1 = first of month

	int dayOfWeek;		//1 = Mon 2 = Tues 3 = Wed 4 = Thurs 5 = Fri 6 = Sat 7 = Sun
};

long long isLeapYear(int year) 
{
	if (year % 100 == 0 && year % 40 == 0
		|| year % 100 != 0 && year % 4 == 0)
	{
		return true;
	}

	return false;
}

Date getNextDate(Date currentDate)
{
	currentDate.dayOfWeek = (currentDate.dayOfWeek % 7) + 1;
	currentDate.day = currentDate.day + 1;

	if (currentDate.month == 2)
	{
		if ((currentDate.day == 29 && !isLeapYear(currentDate.year)) 
			|| currentDate.day == 30)
		{
			currentDate.day = 1;
			currentDate.month = currentDate.month + 1;
		}
	}
	else if (currentDate.month == 1
		|| currentDate.month == 3
		|| currentDate.month == 5
		|| currentDate.month == 7
		|| currentDate.month == 8
		|| currentDate.month == 10)
	{
		if (currentDate.day == 32)
		{
			currentDate.day = 1;
			currentDate.month = currentDate.month + 1;
		}
	}
	else if (currentDate.month == 4
		|| currentDate.month == 6
		|| currentDate.month == 9
		|| currentDate.month == 11)
	{
		if (currentDate.day == 31)
		{
			currentDate.day = 1;
			currentDate.month = currentDate.month + 1;
		}

	}
	else if (currentDate.month == 12)
	{
		if (currentDate.day == 32)
		{
			currentDate.day = 1;
			currentDate.month = 1;
			currentDate.year = currentDate.year + 1;
		}
	}

	return currentDate;
}

long long getAnswer()
{
	Date currentDate;
	currentDate.year = 1900;
	currentDate.month = 1;
	currentDate.day = 1;
	currentDate.dayOfWeek = 1;

	int counter = 0;
	while(currentDate.year < 2001)
	{
		//If it's the first of the month and a Sunday, keep track of this
		//Also, they only want the ones in 1901
		if (currentDate.day == 1 && currentDate.dayOfWeek == 7 && currentDate.year >= 1901)
		{
			counter = counter + 1;
		}

		currentDate = getNextDate(currentDate);
	}

	return counter;
}


int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	//Wait for input 
	std::cin >> result;

	return 0;
}
