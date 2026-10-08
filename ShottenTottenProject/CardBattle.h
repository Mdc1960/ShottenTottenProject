#pragma once
#include "CardTactic.h"
#include "CollinMaillard.h"
#include "CBDecorator.h"

/** 
 * @brief A class representing a battle card.
 * This class inherits from CardTactic and provides an interface for battle cards in the game.
 */
class CardBattle : public CardTactic
{
public:

	/** 
	 * @brief Prints the card.
	 */
	virtual void printCard() = 0;

	/**
	 * @brief Applies the effect of the card to the specified border.
	 * @param border A unique pointer to the border on which the effect will be applied.
	 */
	virtual void applyEffet(unique_ptr<Border>& border) = 0;

	/** 
	 * @brief Gets the name of the card.
	 * @return The name of the card.
	 */
	virtual string getNamecard() = 0;

	/** 
	 * @brief Destructor for the CardBattle class.
	 */
	virtual ~CardBattle() = default;
};