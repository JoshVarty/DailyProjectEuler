// 2016.10.24.Problem29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>

#define MAX_SIZE 500

std::string getStringFromArray(int * myArray)
{
	int index = 0;
	while (myArray[index] == 0)
	{
		index = index + 1;
	}

	std::string outputString;
	outputString.resize(MAX_SIZE - index);
	int strIndex = 0;
	for (int i = index; i < MAX_SIZE; i++)
	{
		char intAsChar = '0' + myArray[i];
		outputString[strIndex] = intAsChar;
		strIndex = strIndex + 1;
	}

	return outputString;
}

int * getArrayForNum(int number)
{
	int * myArray = new int[MAX_SIZE]();

	int index = MAX_SIZE - 1;
	while (number != 0)
	{
		int digit = number % 10;
		myArray[index] = digit;

		number = number / 10;
		index = index - 1;
	}

	return myArray;
}

int MultiplyNumberToResult(int inputArray[], int resultArray[], int column, int number, int carry)
{
	int currentResult = inputArray[column];
	int newResult = currentResult * number + carry;

	resultArray[column] = newResult;

	if (newResult > 9)
	{
		int rightMostDigit = newResult % 10;
		resultArray[column] = rightMostDigit;

		return (newResult - rightMostDigit) / 10;
	}

	return 0;
}	


int * MultiplyArrayByNumber(int backingArray[], int number)
{
	int * resultArray = new int[MAX_SIZE]();
	int carry = 0;
	for (int i = MAX_SIZE - 1; i >= 0; i--)
	{
		carry = MultiplyNumberToResult(backingArray, resultArray, i, number, carry);
	}

	free(backingArray);
	return resultArray;
}

long long getAnswer()
{
	std::set<std::string> uniqueResults;

	for (int a = 2; a <= 100; a++)
	{
		for (int b = 2; b <= 100; b++)
		{
			int *result = getArrayForNum(a);
			for (int i = 0; i < b - 1; i++)
			{
				result = MultiplyArrayByNumber(result, a);
			}
			std::string strResult = getStringFromArray(result);
			uniqueResults.insert(strResult);
		}
		std::cout << a << "\n";
	}

	return uniqueResults.size();
}

int main()
{
	int result = getAnswer();

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;;

	return 0;
}