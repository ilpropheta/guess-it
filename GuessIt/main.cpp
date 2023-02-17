#include <iostream>
#include "Game.h"

int main()
{
	try
	{
		Game game;
		game.Play();
	}
	catch(const std::exception& ex)
	{
		std::cout << "An error occurred: " << ex.what() << "\n";
	}
}

