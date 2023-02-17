#pragma once
#include <stdexcept>

namespace Utils
{
	struct GameStoppedException : std::runtime_error
	{
		GameStoppedException() : std::runtime_error("The game has been stopped by the player") {}
	};


	int PickRandomNumberBetween(int min, int max);
	int ReadNumberFromConsole();
}
