#pragma once
#include "CardElite.h"

#include <iostream>

using namespace std;

/** 
 * @brief A class representing an Espion card.
 * This class inherits from CardElite and provides an interface for Espion cards in the game.
 */
class Espion : public CardElite
{
public:

	/** 
	 * @brief Prints the card.
	 */
	void printCard() override;

	/** 
	 * @brief Gets the name of the card.
	 * @return The name of the card.
	 */
	string getNamecard() override { return "Espion"; }

	/** 
	 * @brief Applies the effect of the card to the specified border.
	 * @param border A unique pointer to the border on which the effect will be applied.
	 */
	void applyEffet(unique_ptr<Border>& border) override;
};