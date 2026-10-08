#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "PlayerInterface.h"

/**
 * @brief Represents a player whose actions are selected by a human.
 */
class HumanPlayer : public PlayerInterface
{
public:
	/**
	 * @brief Constructs a human player.
	 * @param name The player's name.
	 * @param id The player's identifier.
	 */
	HumanPlayer(const std::string& name, unsigned int id);

	/** @brief Prompts the human player to choose a borne. */
	void chooseBorne() override;

	/**
	 * @brief Prompts the human player to claim a borne on the board.
	 * @param bord The board on which the borne is claimed.
	 */
	void claim(Bord& bord) override;

	/** @brief Prompts the human player to choose a card. */
	void chooseCard() override;
};

#endif // HUMAN_PLAYER_H
