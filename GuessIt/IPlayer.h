#pragma once
#include <string>

enum class GameState
{
	FirstGuess, TooSmall, TooLarge, Guessed
};

class IPlayer
{
public:
	virtual int PickNumber(GameState gs) = 0;
	virtual std::string AskName() = 0;
};