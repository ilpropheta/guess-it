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
