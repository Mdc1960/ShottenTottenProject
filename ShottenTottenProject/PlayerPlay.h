#ifndef PLAYER_PLAY_H
#define PLAYER_PLAY_H

#include "Phase.h"


class PlayerPlay : public Phase
{

public :

	void acceptPlayer(PlayerInterface* player) override;
};

#endif