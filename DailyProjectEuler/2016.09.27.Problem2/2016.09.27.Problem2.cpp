// 2016.09.27.Problem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


//Each new term in the Fibonacci sequence is generated by adding the previous two terms.By starting with 1 and 2, the first 10 terms will be :
//1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even - valued terms.

int mySolution()
{
	const int MAX_NUMBER = 4000000;

	long long int sum = 0;
	int lastValue = 1;
	int currentValue = 2;
	while (lastValue < MAX_NUMBER)
	{
		if (lastValue % 2 == 0)
		{
			sum = sum + lastValue;
			std::cout << lastValue << " : " << sum << "\n";
		}

		int temp = lastValue;
		lastValue = currentValue;
		currentValue = currentValue + temp;	//n = (n-1) + (n-2)
	}

	return sum;
}

int anotherSolution()
{
	int x = 0;
	int y = 1;
	int z;
	int sum = 0;

	do {
		z = x + y;
		x = y;
		y = z;
		if (y % 2 == 0) sum += y;
	} while (y <= 4000000);

	return sum;
}

int main()
{
	int result = anotherSolution();
	std::cout << result << "\n";

	result = anotherSolution();
	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;

	return 0;
}

