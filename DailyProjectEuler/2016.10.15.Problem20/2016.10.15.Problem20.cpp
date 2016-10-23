// 2016.10.15.Problem20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//	Find the sum of the digits in the number 100!

#define MAX_SIZE 1000

void prettyPrint(int* numbers, int arraySize)
{
	bool nonZeroSeen = false;
	for (int i = 0; i < arraySize; i++)
	{
		if (numbers[i] != 0)
		{
			nonZeroSeen = true;
		}
		if (nonZeroSeen)
		{
			std::cout << numbers[i] << ", ";
		}
	}
		
	std::cout << "\n";
}

long long GetSum(int * numbers, int arraySize)
{
	long long sum = 0;
	for (int i = 0; i < arraySize; i++)
	{
		sum = sum + numbers[i];
	}
	return sum;
}

int MultiplyNumberToResult(int inputArray[], int resultArray[], int column, int number, int carry)
{
	int currentResult = inputArray[column];
	int newResult = currentResult * number + carry;

	resultArray[column] = newResult;

	if (newResult > 9)
	{
		int rightMostDigit = newResult % 10;	//Technically should be abs but we know its non-negative
		resultArray[column] = rightMostDigit;

		return (newResult - rightMostDigit) / 10;
	}

	return 0;
}

int * backingArray = new int[MAX_SIZE]();

long long getAnswer()
{
	backingArray[MAX_SIZE - 1] = 1;

	for (int number = 1; number <= 100; number++)
	{
		int * resultArray = new int[MAX_SIZE]();

		int carry = 0;
		for (int j = MAX_SIZE - 1; j > 0; j--)
		{
			carry = MultiplyNumberToResult(backingArray, resultArray, j, number, carry);
		}

		free(backingArray);	//Free the last array
		backingArray = resultArray;

		prettyPrint(backingArray, MAX_SIZE);
	}

	return GetSum(backingArray, MAX_SIZE);
}

int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	//Wait for input 
	std::cin >> result;

	return 0;
}
