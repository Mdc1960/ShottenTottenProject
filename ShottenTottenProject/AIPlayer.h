#ifndef AI_PLAYER_H
#define AI_PLAYER_H


#include "PlayerInterface.h"
#include <iostream>
#include <random>

/**
 * @brief The AIPlayer class represents an AI player in the game.
 * It inherits from the PlayerInterface and implements the necessary methods for AI behavior.
 */
class AIPlayer : public PlayerInterface
{

public:

	/**
	 * @brief Constructs an AIPlayer with the specified name and ID.
	 * @param name The name of the AI player.
	 * @param id The unique identifier for the AI player.
	 */
	AIPlayer(const std::string& name, unsigned int id);

	/**
	 * @brief Chooses a card for the AI player.
	 */
	void chooseBorne() override;

	/**
	 * @brief Claims a border for the AI player.
	 * @param bord The Bord object representing the game board.
	 */
	void claim(Bord& bord) override;

	/**
	 * @brief Chooses a card for the AI player.
	 */
	void chooseCard() override;

	/**
	 * @brief Generates a random number within the specified range.
	 * @param maxNumber The maximum value (inclusive).
	 * @param minNumber The minimum value (inclusive).
	 * @return The generated random number.
	 */
	const unsigned int generateRandomNumber(unsigned int&& maxNumber, unsigned int&& minNumber) const;

};

#endif