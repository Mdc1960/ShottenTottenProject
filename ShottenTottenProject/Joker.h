#pragma once
#include "CardElite.h"

#include <iostream>

using namespace std;

/**
 * Represents the Joker elite card.
 */
class Joker : public CardElite
{
public:
	/** Prints the Joker card. */
	void printCard() override;

	/**
	 * Returns this card's name.
	 *
	 * @return the name "Joker"
	 */
	string getNamecard() override { return "Joker"; }

	/**
	 * Applies the Joker's effect to a border.
	 *
	 * @param border the border to which the effect is applied
	 */
	void applyEffet(unique_ptr<Border>& border) override;
};
