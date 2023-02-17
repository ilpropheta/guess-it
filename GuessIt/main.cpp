#include <iostream>

int main()
{
	std::cout << "Guess It!\n";

	const int secretNumber = 59;
	int userNumber = 0;
	std::cout << "Guess the number> ";
	std::cin >> userNumber;
}