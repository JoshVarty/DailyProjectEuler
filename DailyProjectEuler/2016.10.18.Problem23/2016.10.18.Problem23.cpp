// 2016.10.18.Problem23.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>

#define MAX_NUM 28123


int getSumOfDivisors(int currentNumber)
{
	int sumOfDivisors = 1;
	int sqareRoot = sqrt(currentNumber);
	for (int i = 2; i <= sqareRoot; i++)
	{
		if (currentNumber % i == 0)
		{
			//Divisors come in pairs of two
			int other = currentNumber / i;
			sumOfDivisors = sumOfDivisors + i;
			if (i != other)
			{
				sumOfDivisors = sumOfDivisors + other;
			}
		}
	}

	return sumOfDivisors;
}

bool IS_SUM_OF_ABUNDANTS[MAX_NUM + 1] = { false };

long long getAnswer()
{
	std::vector<int> abundantNumbers;

	for (int i = 2; i < MAX_NUM; i++)
	{
		int sum = getSumOfDivisors(i);

		if (sum > i)
		{
			abundantNumbers.push_back(i);
		}
	}

	int listSize = abundantNumbers.size();

	for (int i = 0; i < listSize; i++)
	{
		int x = abundantNumbers[i];

		for (int j = i; j < listSize; j++)
		{
			int y = abundantNumbers[j];

			int sum = x + y;
			if (sum >= MAX_NUM)
				break;

			IS_SUM_OF_ABUNDANTS[sum] = true;
		}
	}

	int sum = 0;
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (IS_SUM_OF_ABUNDANTS[i] == false)
		{
			sum = sum + i;
		}
	}

	return sum;
}


int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	std::cin >> result;

	return 0;
}