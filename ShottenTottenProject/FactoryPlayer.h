#ifndef FACTORY_PLAYER_H
#define FACTORY_PLAYER_H


#include "PlayerInterface.h"

/** 
 * @brief A class representing a factory for creating players.
 * This class provides an interface for creating players in the game.
 */
class FactoryPlayer {

public:

	/** 
	 * @brief Creates a player with the specified name and ID.
	 * @param name The name of the player.
	 * @param id The ID of the player.
	 * @return A unique pointer to the created player.
	 */
	virtual std::unique_ptr<PlayerInterface> createPlayer(const std::string& name, unsigned int id) = 0;

	/** 
	 * @brief Destructor for the FactoryPlayer class.
	 */
	virtual ~FactoryPlayer() = default;

};


#endif;