// 2016.10.23.Problem28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows :
//
//								21 22 23 24 25
//								20  7  8  9 10
//								19  6  1  2 11
//								18  5  4  3 12
//								17 16 15 14 13
//
//It can be verified that the sum of the numbers on the diagonals is 101.
//
//What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way ?

#define MAX_X 1001
#define MAX_Y 1001 

long long getAnswer()
{
	//Holy shit are you seeing this...
	int (*myArray)[MAX_Y] = new int[MAX_X][MAX_Y];

	int current_X = (MAX_X - 1) / 2;
	int current_Y = (MAX_Y - 1) / 2;
	myArray[current_X][current_Y] = 1;

	int xDelta = 1;
	int yDelta = 1;
	int xBound = 1;
	int yBound = 1;

	int currentNumber = 1;
	while ((currentNumber + xBound) <= MAX_X * MAX_Y)
	{
		for (int i = 0; i < xBound; i++)
		{
			currentNumber = currentNumber + 1;
			current_X = current_X + xDelta;
			myArray[current_X][current_Y] = currentNumber;
		}
		
		for (int i = 0; i < xBound; i++)
		{
			currentNumber = currentNumber + 1;
			current_Y = current_Y + yDelta;
			myArray[current_X][current_Y] = currentNumber;
		}

		//Now go the other direction
		xDelta = xDelta * -1;
		yDelta = yDelta * -1;

		xBound = xBound + 1;
		yBound = yBound + 1;
	}

	//Top off that last row. I wonder if anyone will see my laziness.
	//This should all be done in a single loop.
	for (int i = 0; i < xBound - 1; i++)
	{
		currentNumber = currentNumber + 1;
		current_X = current_X + xDelta;
		myArray[current_X][current_Y] = currentNumber;
	}

	long long sum = 0;
	//Now add em up.
	for (int i = 0; i < MAX_X; i++)
	{
		int diag1 = myArray[i][i];
		int diag2 = myArray[MAX_X - i - 1][i];

		sum = sum + diag1;
		if (i != MAX_X - i - 1)
		{
			sum = sum + diag2;
		}
	}

	return sum;
}

int main()
{
	int result = getAnswer();

	std::cout << result << "\n";

	//Don't close the window
	std::cin >> result;;

	return 0;
}