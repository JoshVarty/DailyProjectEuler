// 2016.10.20.Problem25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

#define MAX_SIZE 1000
int currentResult[MAX_SIZE] = { 0 };

int AddNumberToResult(int result[], int column, int number, int carry)
{
	int currentResult = result[column];
	int newResult = currentResult + number + carry;

	result[column] = newResult;

	if (newResult > 9)
	{
		int rightMostDigit = newResult % 10;	//Technically should be abs but we know its non-negative
		result[column] = rightMostDigit;

		return 1;
	}

	return 0;
}

string addTerms(string f_1, string f_2)
{
	int * intf_1 = new int[f_1.length()]();
	int * intf_2 = new int[f_2.length()]();
	
	for (int i = 0; i < f_1.length(); i++)
	{
		char currentChar = f_1[i];
		int digit = atoi(&currentChar);
		intf_1[i] = digit;
	}
	
	for (int i = 0; i < f_2.length(); i++)
	{
		char currentChar = f_2[i];
		int digit = atoi(&currentChar);
		intf_2[i] = digit;
	}

	int resultLength;

	if (f_1.length() > f_2.length())
	{
		resultLength = f_1.length() + 1;
	}
	else
	{
		resultLength = f_2.length() + 1;
	}

	///THESE ARE NOT SET UP RIGHT
	//WE'RE INSERTING AT 0 AND IT SHOULD BE RIGHT ALIGNED
	int * result = new int[resultLength]();
	int resultIndex = resultLength - 1;
	int f1Index = f_1.length() - 1;
	while (f1Index >= 0)
	{
		result[resultIndex] = intf_1[f1Index];
		f1Index = f1Index - 1;
		resultIndex = resultIndex - 1;
	}

	//SAMEHERE
	resultIndex = resultLength - 1;
	int f2Index = f_2.length() - 1;
	int carry = 0;
	while (f2Index >= 0)
	{
		int digit = intf_2[f2Index];
		carry = AddNumberToResult(result, resultIndex, digit, carry);
		f2Index = f2Index - 1;
		resultIndex = resultIndex - 1;
	}

	if (carry != 0)
	{
		carry = AddNumberToResult(result, resultIndex, 0, carry);
	}

	int i = 0;
	//Convert back to string
	for (; i < resultLength; i++)
	{
		if(result[i] != 0)
		{
			break;
		}
	}

	string strResult;
	for (; i < resultLength; i++)
	{
		strResult += to_string(result[i]);
	}

	return strResult;
}


long long getAnswer()
{
	string f_2 = "1";
	string f_1 = "1";

	for (long long i = 3; i < _LLONG_MAX; i++)
	{
		string f = addTerms(f_1, f_2);

		f_2 = f_1;
		f_1 = f;

		int length = f.length();
		std::cout << length << "\n";
		if (length >= 1000)
		{
			return i;
		}
	}

	return -1;
}


int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	std::cin >> result;

	return 0;
}

