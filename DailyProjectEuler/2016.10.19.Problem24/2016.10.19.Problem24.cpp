// 2016.10.19.Problem24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

long long getAnswer()
{
	std::vector<int> container;
	container.push_back(0);
	container.push_back(1);
	container.push_back(2);
	container.push_back(3);
	container.push_back(4);
	container.push_back(5);
	container.push_back(6);
	container.push_back(7);
	container.push_back(8);
	container.push_back(9);

	int counter = 0;
	do
	{
		counter = counter + 1;
		
	} while (counter != 1000000 && std::next_permutation(container.begin(), container.end()));


	std::cout << container[0];
	std::cout << container[1];
	std::cout << container[2];
	std::cout << container[3];
	std::cout << container[4];
	std::cout << container[5];
	std::cout << container[6];
	std::cout << container[7];
	std::cout << container[8];
	std::cout << container[9];
	std::cout << "\n";

	return 0;
}

int main()
{
	long long result = getAnswer();

	std::cout << result << "\n";

	std::cin >> result;

	return 0;
}