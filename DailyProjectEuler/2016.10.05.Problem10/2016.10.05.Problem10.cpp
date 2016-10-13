// 2016.10.05.Problem10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define uint unsigned int

//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.

long long int getAnswer()
{
	bool * myArray = new bool[2000000]();

	for (long long i = 2; i < 1000000; i++)
	{
		int z = i;
		for (long long j = i * 2; j < 2000000; j += i)
		{
			myArray[j] = true;
		}
	}

	long long sumPrimes = 0;
	for (long long i = 2; i < 2000000; i++)
	{
		if (myArray[i] == false)
		{
			sumPrimes += i;
		}
	}

	return sumPrimes;
}

int main()
{
	long long int result = getAnswer();

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;;

    return 0;
}


