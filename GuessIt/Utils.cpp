#include "Utils.h"
#include <iostream>
#include <random>

int Utils::PickRandomNumberBetween(int min, int max)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution uniform_dist(min, max);
    return uniform_dist(e1);
}

int Utils::ReadNumberFromConsole()
{
	int userNumber = 0;
	std::cout << "Guess the number > ";
	std::cin >> userNumber;
	if (std::cin.fail())
	{
		throw std::runtime_error{ "Some error occurred" };
	}
	if (userNumber == 0)
	{
		throw GameStoppedException{};
	}
	return userNumber;
}