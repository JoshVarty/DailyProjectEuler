// 2016.10.17.Problem22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

std::vector<std::string> split(const std::string &s, char delim) 
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

long long getScore(std::string name, int position)
{
	long long sum = 0;
	char firstChar = 'A';

	for (int i = 0; i < name.length(); i++)
	{
		char currentChar = name[i];
		int diff = currentChar - firstChar + 1;
		sum = sum + diff;
	}

	return sum * position;
}

long long getAnswer()
{
	std::ifstream infile("p022_names.txt");

	std::string line;
	std::istringstream iss(line);
	//Read all lines
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		int a, b;
		if (!(iss >> a >> b))
		{
			break;
		}
	}
	
	//Remove "'s
	line.erase(std::remove(line.begin(), line.end(), '"'), line.end());
	//Split on ,
	std::vector<std::string> names = split(line, ',');
	//Sort list
	std::sort(names.begin(), names.end());

	long long totalScore = 0;
	int index = 1;
	for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); ++it) 
	{
		std::string currentName = *it;
		int score = getScore(currentName, index);
		totalScore = totalScore + score;

		index = index + 1;
	}

	return totalScore;
}



int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	//Wait for input 
	std::cin >> result;

	return 0;
}