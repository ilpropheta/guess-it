#include <iostream>
#include "Utils.h"

int main()
{
	std::cout << "GuessIt!\n\n";

	const int secretNumber = Utils::PickRandomNumberBetween(1, 100);
	int userNumber = 0;

	while (userNumber != secretNumber)
	{
		userNumber = Utils::ReadNumberFromConsole();
		if (userNumber > secretNumber)
		{
			std::cout << "Too large. Try again...\n";
		}
		else if (userNumber < secretNumber)
		{
			std::cout << "Too small. Try again...\n";
		}
		else
		{
			std::cout << "Congratulations! It was " << secretNumber << "!\n";
		}
	}
}