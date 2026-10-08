#pragma once
#include "CardInterface.h"
#include "Border.h"

/** 
 * @brief A class representing a tactic card.
 * This class inherits from CardInterface and provides an interface for tactic cards in the game.
 */
class CardTactic : public CardInterface
{
public:

	/** 
	 * @brief Prints the card.
	 */
	virtual void printCard() = 0;

	/** 
	 * @brief Gets the name of the card.
	 * @return The name of the card.
	 */
	virtual string getNamecard() = 0;

	/** 
	 * @brief Applies the effect of the card to the specified border.
	 * @param border A unique pointer to the border on which the effect will be applied.
	 */
	virtual void applyEffet(unique_ptr<Border>& border) = 0;

	/** 
	 * @brief Destructor for the CardTactic class.
	 */
	virtual ~CardTactic() = default;
};

