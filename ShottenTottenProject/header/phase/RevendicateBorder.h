#ifndef REVENDICATE_Border8H
#define REVENDICATE_Border8H

#include "Phase.h"

/**
 * @brief Phase for revendicating a border.
 *
 * Inherits the common phase behavior and defines how a player is accepted
 * during border revendication.
 */
class RevendicateBorder : public Phase
{
public:
	/**
	 * @brief Accepts a player into this phase.
	 * @param player The player to accept.
	 */
	void acceptPlayer(PlayerInterface* player) override;
};

#endif // REVENDICATE_Border8H
