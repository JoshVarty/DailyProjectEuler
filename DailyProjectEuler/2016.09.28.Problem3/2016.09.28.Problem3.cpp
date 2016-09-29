// 2016.09.28.Problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>

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

	for (int i = 2; i < root; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int getBiggestPrimeFactor(long long int number, long long int candidateFactor)
{
	for (int i = candidateFactor - 1; i > 1; i--)
	{
		if (number % i == 0 && isPrime(i))
		{
			return i;
		}
	}

	return candidateFactor;
}



int main()
{
	long long int number = 600851475143;
	long long int root = sqrt(number);

	int result = getBiggestPrimeFactor(number, root);

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;

    return 0;
}


