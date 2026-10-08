#ifndef FACTORY_HUMAN_PLAYER_H
#define FACTORY_HUMAN_PLAYER_H


#include "FactoryPlayer.h"
#include "HumanPlayer.h"

/** 
 * @brief A class representing a factory for creating human players.
 * This class inherits from FactoryPlayer and provides an interface for creating human players in the game.
 */
class FactoryHumanPlayer : public FactoryPlayer
{

public:

	/** 
	 * @brief Creates a human player with the specified name and ID.
	 * @param name The name of the human player.
	 * @param id The ID of the human player.
	 * @return A unique pointer to the created human player.
	 */
	std::unique_ptr<PlayerInterface> createPlayer(const std::string& name, unsigned int id) override;
};

#endif