#include "Game.h"
#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Utils.h"

const int MinGuess = 1;
const int MaxGuess = 100;

void Game::Play()
{
	std::cout << "GuessIt!\n\n";

	try
	{
		for (auto i=0; i<10; ++i)
		{
			const int secretNumber = Utils::PickRandomNumberBetween(MinGuess, MaxGuess);
			ComputerPlayer player{ MinGuess, MaxGuess };
			PlayGame(secretNumber, player);
		}
	}
	catch (const Utils::GameStoppedException&)
	{
		std::cout << "The game has been terminated\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << "An error occurred: " << ex.what() << "\n";
	}

	std::ranges::sort(m_leaderboard, [](const LeaderboardEntry& first, const LeaderboardEntry& second) {
		return first.Attempts < second.Attempts;
	});
}

void Game::PrintLeaderboard() const
{
	std::cout << "\nLeaderboard:\n";
	for (const auto& [name, attempts] : m_leaderboard)
		std::cout << name << " attempts: " << attempts << "\n";
}

void Game::PlayGame(int secretNumber, IPlayer& player)
{
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
			m_leaderboard.emplace_back(name, attempts);
			gameState = GameState::Guessed;
		}
	}
}
