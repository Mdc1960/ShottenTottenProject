#ifndef COLIN_MAILLARD_CARD_H
#define COLIN_MAILLARD_CARD_H

#include "CardBattle.h"

/** 
 * @brief A class representing a Colin Maillard card.
 * This class inherits from CardBattle and provides an interface for Colin Maillard cards in the game.
 */
class ColinMaillardCard : public CardBattle
{
public:

	/** 
	 * @brief Prints the card.
	 */
	void printCard() override;

	/** 
	 * @brief Applies the effect of the card to the specified border.
	 * @param border A unique pointer to the border on which the effect will be applied.
	 */
	void applyEffet(unique_ptr<Border>& border) override;
	
	/** 
	 * @brief Gets the name of the card.
	 * @return The name of the card.
	 */
	string getNamecard() override;

};

#endif