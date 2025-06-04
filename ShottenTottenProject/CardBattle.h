#pragma once
#include "CardTactic.h"
class CardBattle : public CardTactic
{
public:
	virtual void applyEffet() = 0;
	virtual string getNamecard() = 0;
};