#pragma once
#include <string>
#include <vector>

class IPlayer;

struct LeaderboardEntry
{
	std::string Name;
	int Attempts;
};

class Game
{
public:
	void Play();
private:
	void PlayGame(int secretNumber, IPlayer& player);

	std::vector<LeaderboardEntry> m_leaderboard;
};