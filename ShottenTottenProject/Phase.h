#ifndef GAME_PHESE_H
#define GAME_PHESE_H

#include "PlayerInterface.h"

class PlayerInterface;

/**
 * @brief Abstract base class for a phase of the game.
 *
 * Derived classes implement the behavior for accepting a player into a phase.
 */
class Phase
{
public:
	/**
	 * @brief Accepts a player into this phase.
	 * @param player Pointer to the player to accept.
	 */
	virtual void acceptPlayer(PlayerInterface* player) = 0;

	/** @brief Virtual destructor for safe destruction of derived phases. */
	virtual ~Phase() {}
};

#endif
