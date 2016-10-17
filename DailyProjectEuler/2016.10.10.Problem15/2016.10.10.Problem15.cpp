// 2016.10.10.Problem15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define X_BOUNDARY 20
#define Y_BOUNDARY 20

long long processGrid(long long lookup[X_BOUNDARY][Y_BOUNDARY], int x, int y)
{
	if (x == X_BOUNDARY && y == Y_BOUNDARY)
	{
		return 1;
	}

	if (x == X_BOUNDARY)
	{
		return processGrid(lookup, x, y + 1);
	}

	if (y == Y_BOUNDARY)
	{
		return processGrid(lookup, x + 1, y);
	}

	if (lookup[x][y] != -1)
	{
		return lookup[x][y];
	}

	long long rightFirst = processGrid(lookup, x + 1, y);
	long long downFirst = processGrid(lookup, x, y + 1);

	long long sum = rightFirst + downFirst;

	lookup[x][y] = sum;

	return sum;
}

long long getAnswer()
{
	long long lookup[X_BOUNDARY][Y_BOUNDARY];

	for (int i = 0; i < X_BOUNDARY; i++)
	{
		for (int j = 0; j < X_BOUNDARY; j++)
		{
			lookup[i][j] = -1;
		}
	}

	return processGrid(lookup, 0, 0);
}


int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	//Wait for input 
	std::cin >> result;

	return 0;
}

