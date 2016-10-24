// 2016.10.16.Problem21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>

#define MAX_SIZE 10001

int divisorSum[MAX_SIZE] = { 0 };

int getSumOfDivisors(int currentNumber)
{
	if (currentNumber > MAX_SIZE - 1)
	{
		return -1;
	}

	if (divisorSum[currentNumber] != 0)
	{
		return divisorSum[currentNumber];
	}

	int sumOfDivisors = 1;
	int sqareRoot = sqrt(currentNumber);
	for (int i = 2; i < sqareRoot; i++)
	{
		if (currentNumber % i == 0)
		{
			//Divisors come in pairs of two
			int other = currentNumber / i;
			sumOfDivisors = sumOfDivisors + i;
			sumOfDivisors = sumOfDivisors + other;
		}
	}

	if (sqareRoot * sqareRoot == currentNumber)
	{
		sumOfDivisors = sumOfDivisors + sqareRoot;
	}

	divisorSum[currentNumber] = sumOfDivisors;
	return sumOfDivisors;
}

long long getAnswer()
{
	std::set<int> setOfNumbers;

	for (int i = 284; i < MAX_SIZE; i++)
	{
		int sumOfDivisors = getSumOfDivisors(i);
		int sumOfDivisors2 = getSumOfDivisors(sumOfDivisors);

		if (sumOfDivisors2 == i && i != sumOfDivisors)
		{
			setOfNumbers.insert(i);
			setOfNumbers.insert(sumOfDivisors);
		}
	}

	int sum = 0;
	std::set<int>::iterator it;
	for (it = setOfNumbers.begin(); it != setOfNumbers.end(); ++it)
	{
		int number = *it; // Note the "*" here
		sum = sum + number;
	}	

	return sum;
}

int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	//Wait for input 
	std::cin >> result;

	return 0;
}
