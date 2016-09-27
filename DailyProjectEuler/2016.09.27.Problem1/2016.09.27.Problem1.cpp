// 2016.09.27.Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// https://projecteuler.net/problem=1
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
// The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

int mySolution()
{
	int sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum = sum + i;
		}
	}
	
	return sum;
}

//We can also represent this as three arithmetic series.
int arithmeticSeriesSolution()
{
	// 3 + 6 +....+999 = 3 ( 1 + 2+ ...+333) =3 * ( 333 * 334)
	unsigned int sum_mult_3_upto_1000 = 3 * 333 * 334 >> 1;
	unsigned int sum_mult_5_upto_1000 = 5 * 199 * 200 >> 1;
	unsigned int sum_mult_15_upto_1000 = 15 * 67 * 66 >> 1;

	unsigned sum = sum_mult_3_upto_1000 + sum_mult_5_upto_1000 
		- sum_mult_15_upto_1000;
	
	return sum;
}


int main()
{
	int result = mySolution();
	std::cout << result << "\n";
	
	result = arithmeticSeriesSolution();
	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;

	return 0;
}
