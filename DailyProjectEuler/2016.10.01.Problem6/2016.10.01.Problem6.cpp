// 2016.10.01.Problem6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

//	The sum of the squares of the first ten natural numbers is,
//
//		1^2 + 2^2 + ... + 10^2 = 385
//
//	The square of the sum of the first ten natural numbers is,
//
//		(1 + 2 + ... + 10)^2 = 552 = 3025
//
//	Hence the difference between the sum of the squares of the first ten natural numbers 
//	and the square of the sum is 3025 − 385 = 2640.
//
//	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


int getAnswer()
{
	long long int sumOfSquares = 0;
	long long int sums = 0;

	for (int i = 1; i <= 100; i++)
	{
		int square = pow(i, 2);
		sumOfSquares = sumOfSquares + square;
		sums = sums + i;
	}

	long long int squareOfSums = sums * sums;
	long long int difference = squareOfSums - sumOfSquares;

	return difference;
}



int main()
{
	int result = getAnswer();

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;;

    return 0;
}

