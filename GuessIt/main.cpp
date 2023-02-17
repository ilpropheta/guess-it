#include <iostream>

int main()
{
	std::cout << "Guess It!\n";

	const int secretNumber = 59;
	int userNumber = 0;

	while (userNumber != secretNumber)
	{
		std::cout << "Guess the number> ";
		std::cin >> userNumber;
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