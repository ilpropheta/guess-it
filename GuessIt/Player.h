#pragma once

#include <functional>

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

class CustomPlayer : public IPlayer
{
public:
	CustomPlayer(const std::string& name, std::function<int(GameState)> logic);
	std::string AskName() override;
	int PickNumber(GameState gs) override;
private:
	std::string m_name;
	std::function<int(GameState)> m_logic;
};