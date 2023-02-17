#pragma once

#include "IPlayer.h"

class Player : public IPlayer
{
public:
	int PickNumber(GameState gs) override;
};

class ComputerPlayer : public IPlayer
{
public:
	ComputerPlayer(int min, int max);
	int PickNumber(GameState gs) override;
private:
	int m_min;
	int m_max;
	int m_current = 0;
};