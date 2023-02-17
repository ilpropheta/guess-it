#include <iostream>
#include "Utils.h"
#include "Player.h"

void PlayGame()
{
	std::cout << "GuessIt!\n\n";
	const int secretNumber = Utils::PickRandomNumberBetween(1, 100);

	Player player;
	GameState gameState = GameState::FirstGuess;
	while (gameState != GameState::Guessed)
	{
		const auto userNumber = player.PickNumber(gameState);
		if (userNumber > secretNumber)
		{
			gameState = GameState::TooLarge;
		}
		else if (userNumber < secretNumber)
		{
			gameState = GameState::TooSmall;
		}
		else
		{
			std::cout << "Congratulations! It was " << secretNumber << "!\n";
			gameState = GameState::Guessed;
		}
	}
}

int main()
{
	try
	{
		PlayGame();
	}
	catch(const Utils::GameStoppedException&)
	{
		std::cout << "The game has been terminated\n";
	}
	catch(const std::exception& ex)
	{
		std::cout << "An error occurred: " << ex.what() << "\n";
	}
}

