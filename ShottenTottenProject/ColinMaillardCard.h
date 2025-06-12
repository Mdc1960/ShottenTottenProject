#ifndef COLIN_MAILLARD_CARD_H
#define COLIN_MAILLARD_CARD_H

#include "CardBattle.h"

class ColinMaillardCard : public CardBattle
{
public:
	void printCard() override;
	void applyEffet() override;
	string getNamecard() override;

};

#endif