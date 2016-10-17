// 2016.10.11.Problem16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "2016.10.11.Problem16.h"

//	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
//	What is the sum of the digits of the number 2^1000 ?

#define MAX_SIZE 1000

class BigInteger {
private:
    int backingArray[MAX_SIZE] = { 0 };

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


public:
    BigInteger()
    {
        backingArray[MAX_SIZE - 1] = 1;
    }

    int GetSumOfDigits()
    {
        int sum = 0;
        for (int i = 0; i < MAX_SIZE; i++)
        {
            sum = sum + backingArray[i];
        }
        return sum;
    }

    BigInteger& operator+=(BigInteger& other)
    {
        int carry = 0;
        for (int i = MAX_SIZE - 1; i >= 0; i--)
        {
            int num = other.backingArray[i];
            carry = AddNumberToResult(this->backingArray, i, num, carry);
        }

        return *this;
    }
};

long long getAnswer()
{
    BigInteger * bigInteger = new BigInteger();
    for (int i = 0; i < MAX_SIZE; i++)
    {
        *bigInteger += *bigInteger;
    }
    
    int sum = bigInteger->GetSumOfDigits();
    free(bigInteger);

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
