#ifndef FIGHT_MUD_CARD
#define FIGHT_MUD_CARD

#include "CardBattle.h"



class CombatDeBoueCard : public CardBattle
{
public:
	void printCard() override;
	void applyEffet(unique_ptr<Border>& border) override;
	string getNamecard() override;
};

#endif