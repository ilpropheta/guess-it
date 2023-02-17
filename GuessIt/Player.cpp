#include "Player.h"
#include "Utils.h"

int Player::PickNumber(GameState gs)
{
	return Utils::ReadNumberFromConsole();
}
