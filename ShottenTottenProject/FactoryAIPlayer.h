#ifndef FACTORY_AI_PLAYER_H
#define FACTORY_AI_PLAYER_H


#include "FactoryPlayer.h"
#include "AIPlayer.h"

/** 
 * @brief A class representing a factory for creating AI players.
 * This class inherits from FactoryPlayer and provides an interface for creating AI players in the game.
 */
class FactoryAIPlayer : public FactoryPlayer
{

public:

	/** 
	 * @brief Creates an AI player with the specified name and ID.
	 * @param name The name of the AI player.
	 * @param id The ID of the AI player.
	 * @return A unique pointer to the created AI player.
	 */
	std::unique_ptr<PlayerInterface> createPlayer(const std::string& name, unsigned int id) override;
};

#endif