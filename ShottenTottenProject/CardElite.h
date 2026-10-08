#pragma once
#include"CardClan.h"
#include"CardTactic.h"

/** 
 * @brief A class representing an elite card.
 * This class inherits from both CardClan and CardTactic, providing an interface for elite cards in the game.
 */
class CardElite : public CardClan, public CardTactic
{
public :

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
	 * @brief Destructor for the CardElite class.
	 */
	virtual ~CardElite() = default;
};

