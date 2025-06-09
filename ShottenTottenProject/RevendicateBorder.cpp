#include "RevendicateBorder.h"
#include "Bord.h"

void RevendicateBorder::acceptPlayer(PlayerInterface* player)
{
	player->claim(Bord::getInstance());
}
