#include "Player.h"
#include <iostream>
#include <numeric>
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

std::string GenerateAlphabet()
{
	std::string alphabet(26, 'a'); // "aaaa..."
	std::iota(begin(alphabet), end(alphabet), 'a'); // "abcd..."
	return alphabet;
}

std::string ComputerPlayer::AskName()
{
	static const std::string alphabet = GenerateAlphabet();
	std::string name;
	for (auto i=0; i<5; ++i)
	{
		name.push_back(alphabet[Utils::PickRandomNumberBetween(0, 25)]);
	}
	return name;
}

CustomPlayer::CustomPlayer(const std::string& name, std::function<int(GameState)> logic)
	: m_name(name), m_logic(logic)
{
}

std::string CustomPlayer::AskName()
{
	return m_name;
}

int CustomPlayer::PickNumber(GameState gs)
{
	return m_logic(gs);
}
