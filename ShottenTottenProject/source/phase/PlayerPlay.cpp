#include "PlayerPlay.h"
#include "Bord.h"

void PlayerPlay::acceptPlayer(PlayerInterface* player)
{
	player->play(Bord::getInstance());
}
