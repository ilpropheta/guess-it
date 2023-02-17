#pragma once

enum class GameState
{
	FirstGuess, TooSmall, TooLarge, Guessed
};

class Player
{
public:
	int PickNumber(GameState gs);
};