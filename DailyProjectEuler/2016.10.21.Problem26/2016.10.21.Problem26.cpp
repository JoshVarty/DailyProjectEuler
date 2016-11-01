// 2016.10.21.Problem26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define MAX_SIZE 1000 


int getCycleLength(int divisor)
{
	int * firstSeen = new int[MAX_SIZE]();

	for (int i = 0; i < MAX_SIZE; i++)
	{
		firstSeen[i] = -1;
	}

	int remainder = 1;
	int index = 0;
	while (remainder != 0 && firstSeen[remainder] == -1)
	{
		firstSeen[remainder] = index;

		remainder = remainder * 10;
		remainder = remainder % divisor;

		index = index + 1;
	}

	int cycleLength = index - firstSeen[remainder];
	free(firstSeen);
	
	if (remainder == 0)
	{
		return 0;
	}

	return cycleLength;
}


long long getAnswer()
{
	int maxCycleLength = 0;
	int numWithMaxCycle = -1;
	
	for (int i = 2; i < 1000; i++)
	{
		int cycleLength = getCycleLength(i);
		if (cycleLength > maxCycleLength)
		{
			maxCycleLength = cycleLength;
			numWithMaxCycle = i;
		}
	}

	return numWithMaxCycle;
}

int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	std::cin >> result;

	return 0;
}
