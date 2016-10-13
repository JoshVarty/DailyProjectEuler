// 2016.10.04.Problem9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//
//	a^2 + b^2 = c^2
//	For example, 32 + 42 = 9 + 16 = 25 = 52.
//
//	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//	Find the product abc.

int getAnswer()
{
	for (int a = 1; a < 999; a++)
	{
		int aSquared = a * a;
		for (int b = 1; b < 999; b++)
		{
			int bSquared = b * b;
			int aSquaredPlusBSquared = aSquared + bSquared;
			for (int c = 1; c < 999; c++)
			{
				int cSquared = c * c;
				if (aSquaredPlusBSquared == cSquared && a + b + c == 1000)
				{
					return a * b * c;
				}
			}
		}
	}

	return -1;
}

int main()
{
	long long int result = getAnswer();

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;;

    return 0;
}

