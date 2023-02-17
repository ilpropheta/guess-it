#pragma once

enum class GameState
{
	FirstGuess, TooSmall, TooLarge, Guessed
};

class IPlayer
{
public:
	virtual int PickNumber(GameState gs) = 0;
};