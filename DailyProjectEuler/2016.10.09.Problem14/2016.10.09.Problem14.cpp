// 2016.10.09.Problem14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


//	The following iterative sequence is defined for the set of positive integers :
//
//	n → n / 2 (n is even)
//	n → 3n + 1 (n is odd)
//
//	Using the rule above and starting with 13, we generate the following sequence :
//
//	13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
//	Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
//
//	Which starting number, under one million, produces the longest chain ?
//
//	NOTE : Once the chain starts the terms are allowed to go above one million.

long long getChainLength(long long number)
{
	long long count = 1;
	while (number > 1)
	{
		count++;
		if (number % 2 == 0)
		{
			number = number / 2;
		}
		else
		{
			number = (3 * number) + 1;
		}
	}

	return count;
}

long long getAnswer()
{
	long long biggestChainLength = 0;
	long long numberWithBiggestChain = 0;

	for (long long i = 1; i < 1000000; i++)
	{
		long long chainLength = getChainLength(i);
		if (chainLength > biggestChainLength)
		{
			numberWithBiggestChain = i;
			biggestChainLength = chainLength;
		}
	}

	return numberWithBiggestChain;
}


int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	//Wait for input 
	std::cin >> result;

	return 0;
}
