#ifndef FIGHT_MUD_CARD
#define FIGHT_MUD_CARD

#include "CardBattle.h"


/** 
 * @brief A class representing a Combat de Boue card.
 * This class inherits from CardBattle and provides an interface for Combat de Boue cards in the game.
 */
class CombatDeBoueCard : public CardBattle
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