// 2016.10.22.Problem27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define AMAX 1000
#define BMAX 1000

int * knownPrimes;

bool isPrime(long long number)
{
	number = abs(number);
	if (number == 0) return false;
	if (number == 1)
	{
		return false;
	}
	if (number == 2)
	{
		return true;
	}

	if (knownPrimes[number] == 1)
	{
		return true;
	}
	else if (knownPrimes[number] == -1)
	{
		return false;
	}

	long long int root = sqrt(number);

	for (long long int i = 2; i <= root; i++)
	{
		if (number % i == 0)
		{
			knownPrimes[number] = -1;
			return false;
		}
	}

	knownPrimes[number] = 1;
	return true;
}

int getNumberOfPrimes(int a, int b)
{
	int primesSoFar = 0;
	int n = 0;
	bool numberIsPrime = true;

	do
	{
		n = n + 1;
		long long result = n * n + a * n + b;
		bool numberIsPrime = isPrime(result);

	} while (numberIsPrime);

	return n;
}

long long getAnswer()
{
	knownPrimes = new int[INT32_MAX]();

	int currentMax = 0;
	int maxA = 0;
	int maxB = 0;

	for (int a = -1000; a < AMAX; a++)
	{
		for (int b = -1000; b < BMAX; b++)
		{
			int numberOfPrimes = getNumberOfPrimes(a, b);
			if (numberOfPrimes > currentMax)
			{
				currentMax = numberOfPrimes;
				maxA = a;
				maxB = b;
			}
		}
	}

	return maxA * maxB;
}

int main()
{
	int result = getAnswer();

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;;

    return 0;
}

