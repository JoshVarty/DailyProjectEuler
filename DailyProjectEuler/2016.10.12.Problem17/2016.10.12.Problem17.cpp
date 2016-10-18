// 2016.10.12.Problem17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

std::string getThousands(int number)
{
    if (number == 0) return "";
	if (number == 1) return "one thousand";

	std::cout << "Error";
}

std::string getHundreds(int number)
{
	if (number == 0) return "";
	if (number == 1) return "one hundred";
	if (number == 2) return "two hundred";
	if (number == 3) return "three hundred";
	if (number == 4) return "four hundred";
	if (number == 5) return "five hundred";
	if (number == 6) return "six hundred";
	if (number == 7) return "seven hundred";
	if (number == 8) return "eight hundred";
	if (number == 9) return "nine hundred";

	std::cout << "Error";
}

std::string getTens(int number)
{
	if (number == 0) return "";
    if (number == 2) return "twenty";
    if (number == 3) return "thirty";
    if (number == 4) return "forty";
    if (number == 5) return "fifty";
    if (number == 6) return "sixty";
    if (number == 7) return "seventy";
    if (number == 8) return "eighty";
    if (number == 9) return "ninety";

	std::cout << "Error";
}

std::string getOnes(int number)
{
	if (number == 0) return "";
	if (number == 1) return "one";
    if (number == 2) return "two";
    if (number == 3) return "three";
    if (number == 4) return "four";
    if (number == 5) return "five";
    if (number == 6) return "six";
    if (number == 7) return "seven";
    if (number == 8) return "eight";
    if (number == 9) return "nine";

    if (number == 10) return "ten";
    if (number == 11) return "eleven";
    if (number == 12) return "twelve";
    if (number == 13) return "thirteen";
    if (number == 14) return "fourteen";
    if (number == 15) return "fifteen";
    if (number == 16) return "sixteen";
    if (number == 17) return "seventeen";
    if (number == 18) return "eighteen";
    if (number == 19) return "nineteen";

	std::cout << "Error";
}

long long getAnswer()
{
    int sumDigits = 0;

	for (int i = 1; i <= 1000; i++)
	{
		int thousandsDigit = (int)abs(i / 1000 % 10);
		int hundredsDigit = (int)abs(i / 100 % 10);
		int tensDigit = (int)abs(i / 10 % 10);
		int oneDigit = (int)abs(i % 10);

		std::string thousands = getThousands(thousandsDigit);
		std::string hundreds = getHundreds(hundredsDigit);
		std::string ones = getOnes(oneDigit);

        std::string tens = "";
        if (tensDigit == 1)
        {
            int tensAndOnes = i % 100;
            ones = getOnes(tensAndOnes);
        }
        else
        {
            tens = getTens(tensDigit);
        }

        std::string result = "";
        result += thousands;
        result += " ";
        result += hundreds;
        if (hundreds != "" && (tens != "" || ones != ""))
        {
            result += " and ";
        }

        if (tensDigit != 1)
        {
            result += tens;
        }

        result += ones;
        std::cout << result << "\n";
        
        result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
        sumDigits += result.length();
	}

	return sumDigits;
}

int main()
{
    long long result = getAnswer();

    std::cout << result << "\n";

    //Wait for input 
    std::cin >> result;

    return 0;
}

