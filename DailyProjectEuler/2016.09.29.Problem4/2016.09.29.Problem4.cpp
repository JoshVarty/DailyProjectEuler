// 2016.09.29.Problem4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

//A palindromic number reads the same both ways.
//The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.
//
//Find the largest palindrome made from the product of two 3 - digit numbers.


bool isPalindrome(int number)
{
	std::string strNumber = std::to_string(number);
	int length = strNumber.length();

	for (int i = 0; i < length / 2; i++)
	{
		char x = strNumber[i];
		char y = strNumber[length - i - 1];
		if (x != y)
		{
			return false;
		}
	}

	return true;
}

int getLargestPalindrome()
{
	int biggest = 0;
	for (int i = 100; i < 999; i++)
	{
		for (int j = 100; j < 999; j++)
		{
			int result = i * j;
			if (result > biggest && isPalindrome(result))
			{
				biggest = result;
			}
		}
	}
	return biggest;
}

int main()
{
	int answer = getLargestPalindrome();
    return 0;
}

