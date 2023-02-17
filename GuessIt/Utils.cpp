#include "Utils.h"
#include <iostream>
#include <random>

int PickRandomNumberBetween(int min, int max)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution uniform_dist(min, max);
    return uniform_dist(e1);
}

int ReadNumberFromConsole()
{
	int userNumber = 0;
	std::cout << "Guess the number > ";
	std::cin >> userNumber;
	return userNumber;
}