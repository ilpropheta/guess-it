#include <iostream>
#include "Utils.h"
#include "Player.h"

const int MinGuess = 1;
const int MaxGuess = 100;

void PlayGame(int secretNumber, IPlayer& player)
{
	std::cout << "GuessIt!\n\n";

	int attempts = 0;
	GameState gameState = GameState::FirstGuess;
	while (gameState != GameState::Guessed)
	{
		++attempts;
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
			const auto name = player.AskName();
			std::cout << "Congratulations " << name << "! It was " << secretNumber << "! It took you " << attempts << " attempts\n";
			gameState = GameState::Guessed;
		}
	}
}

int main()
{
	try
	{
		const int secretNumber = Utils::PickRandomNumberBetween(MinGuess, MaxGuess);
		ComputerPlayer player {MinGuess, MaxGuess};
		PlayGame(secretNumber, player);
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

