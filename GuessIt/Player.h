#pragma once

#include "IPlayer.h"

class Player : public IPlayer
{
public:
	int PickNumber(GameState gs) override;
	std::string AskName() override;
};

class ComputerPlayer : public IPlayer
{
public:
	ComputerPlayer(int min, int max);
	int PickNumber(GameState gs) override;
	std::string AskName() override;
private:
	int m_min;
	int m_max;
	int m_current = 0;
};