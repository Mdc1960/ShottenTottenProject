#ifndef GAME_TACTIC_H
#define GAME_TACTIC_H

#include "Game.h"

/**
 * @brief Represents a tactics game.
 *
 * Extends the base Game class with the setup and gameplay behavior for a
 * tactics game.
 */
class GameTactic : public Game
{

public:

	/**
	 * @brief Constructs a tactics game.
	 */
	GameTactic();

	/**
	 * @brief Starts the tactics game.
	 *
	 * Implements the startGame operation declared by Game.
	 */
	void startGame() override;
};

#endif
