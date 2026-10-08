#pragma once
#include "CardTactic.h"

/** 
 * @brief A class representing a ruse card.
 * This class inherits from CardTactic and provides an interface for ruse cards in the game.
 */
class Ruse : public CardTactic
{
public :

	/**
	 * @brief Applies the effect of the card to the specified border.
	 * @param border A unique pointer to the border on which the effect will be applied.
	 */
	void applyEffet(unique_ptr<Border>& border) = 0;
	
	/** 
	 * @brief Gets the name of the card.
	 * @return The name of the card.
	 */
	string getNamecard() = 0;
};

