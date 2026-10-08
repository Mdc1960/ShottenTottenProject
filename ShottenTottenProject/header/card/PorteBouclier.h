#pragma once
#include "CardElite.h"

#include <iostream>

using namespace std;

/**
 * @brief Represents the Porte-Bouclier elite card.
 *
 * The card can apply its special effect to a border.
 */
class PorteBouclier : public CardElite
{
public:
	/** @brief Prints information about this card. */
	void printCard() override;

	/**
	 * @brief Returns the display name of this card.
	 * @return The name "Porte-Bouclier".
	 */
	string getNamecard() override { return "Porte-Bouclier"; }

	/**
	 * @brief Applies this card's effect to a border.
	 * @param border Reference to the border affected by the effect.
	 */
	void applyEffet(unique_ptr<Border>& border) override;
};
