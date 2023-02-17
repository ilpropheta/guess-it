#include "Player.h"
#include <iostream>
#include "Utils.h"

int Player::PickNumber(GameState gs)
{
	switch (gs)
	{
	case GameState::FirstGuess: 
		break;
	case GameState::TooSmall: 
		std::cout << "Too small...try again\n";
		break;
	case GameState::TooLarge: 
		std::cout << "Too large...try again\n";
		break;
	case GameState::Guessed: 
		break;
	}
	return Utils::ReadNumberFromConsole();
}

std::string Player::AskName()
{
	std::string name;
	std::cout << "Your name> ";
	std::cin >> name;
	return name;
}

ComputerPlayer::ComputerPlayer(int min, int max)
	: m_min(min), m_max(max)
{
}

int ComputerPlayer::PickNumber(GameState gs)
{
	switch (gs)
	{
	case GameState::FirstGuess: 
		break;
	case GameState::TooSmall: 
		m_min = m_current + 1;
		break;
	case GameState::TooLarge: 
		m_max = m_current - 1;
		break;
	case GameState::Guessed: 
		break;
	}
	return m_current = m_min + (m_max - m_min) / 2;
}

std::string ComputerPlayer::AskName()
{
	return "pc";
}
