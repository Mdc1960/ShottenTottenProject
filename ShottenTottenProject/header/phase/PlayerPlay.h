/**
 * @file PlayerPlay.h
 * Declares the player-play phase.
 */
#ifndef PLAYER_PLAY_H
#define PLAYER_PLAY_H

#include "Phase.h"

/**
 * A phase in which a player performs their play.
 */
class PlayerPlay : public Phase
{

public:

	/**
	 * Accepts the player participating in this phase.
	 *
	 * @param player pointer to the player to accept
	 */
	void acceptPlayer(PlayerInterface* player) override;
};

#endif
