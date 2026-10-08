#ifndef COLLIN_MAILLARD_H
#define COLLIN_MAILLARD_H

#include "BorderDecorator.h"

/** 
 * @brief A class representing the Collin Maillard border decorator.
 * This class inherits from BorderDecorator and provides an interface for the Collin Maillard effect in the game.
 */
class CollinMaillard : public BorderDecorator
{
private:

	/** 
	 * @brief Calculates the score based on the given number.
	 * @param numero The number to calculate the score from.
	 * @return The calculated score.
	 */
	unsigned int calculerScore(unsigned int numero);

public :

	/** 
	 * @brief Constructs a new Collin Maillard object with the specified inner Border.
	 * @param comp A unique pointer to the inner Border object to be decorated.
	 */
	CollinMaillard(std::unique_ptr<Border> comp)
		: BorderDecorator(std::move(comp)) {};

	/** 
	 * @brief Claims the border.
	 * @return The ID of the player who claimed the border.
	 */
	unsigned int claim() override;
};

#endif