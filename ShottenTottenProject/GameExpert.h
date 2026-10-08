#ifndef GAME_EXPERT_H
#define GAME_EXPERT_H

#include "Game.h"

/**
 * @brief Represents a game played at expert difficulty.
 *
 * Extends Game with expert-mode behavior.
 */
class GameExpert : public Game
{
public:
	/** @brief Constructs an expert-mode game. */
	GameExpert();

	/**
	 * @brief Starts the expert-mode game.
	 *
	 * Overrides Game::startGame().
	 */
	void startGame() override;
};

#endif // GAME_EXPERT_H
