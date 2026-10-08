#ifndef GAME_BASE_H
#define GAME_BASE_H

#include "Game.h"

/**
 * @brief Provides the base implementation for a game.
 *
 * GameBase inherits the common game interface and implements the game-start
 * operation.
 */
class GameBase : public Game
{

public:

	/**
	 * @brief Constructs a GameBase instance.
	 */
	GameBase();

	/**
	 * @brief Starts the game.
	 */
	void startGame() override;

};

#endif
