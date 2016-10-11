// 2016.09.30.Problem5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <climits>

// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// 
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?


bool isDivisibleByOneToTwenty(int number)
{
	for (int i = 1; i <= 20; i++)
	{
		if (number % i != 0)
		{
			return false;
		}
	}

	return true;
}

int getAnswer()
{
	long long int maxNumber = LLONG_MAX;
	for (int i = 1; i < maxNumber; i++)
	{
		if (isDivisibleByOneToTwenty(i))
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int result = getAnswer();

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;

	return 0;
}

