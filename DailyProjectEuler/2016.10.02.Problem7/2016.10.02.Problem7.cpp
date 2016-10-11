// 2016.10.02.Problem7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <climits>


//	By listing the first six prime numbers : 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//
//	What is the 10 001st prime number ?

bool isPrime(long long int number)
{
	if (number == 1)
	{
		return false;
	}
	if (number == 2)
	{
		return true;
	}

	long long int root = sqrt(number);

	for (long long int i = 2; i <= root; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

long long int getAnswer()
{
	int numberOfPrimes = 0;
	for (long long int i = 1; i < LONG_MAX; i++)
	{
		if (isPrime(i))
		{
			numberOfPrimes = numberOfPrimes + 1;
			if (numberOfPrimes == 10001)
			{
				return i;
			}
		}
	}
}

int main()
{
	long long int result = getAnswer();

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;;

    return 0;
}

