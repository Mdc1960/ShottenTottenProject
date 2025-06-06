#ifndef GAME_PHESE_H
#define GAME_PHESE_H

#include "PlayerInterface.h"

class PlayerInterface;

class Phase
{

public :

	virtual void acceptPlayer(PlayerInterface* player) = 0;
	virtual ~Phase(){}

};

#endif