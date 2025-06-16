#pragma once
#include"CardClan.h"
#include"CardTactic.h"

class CardElite : public CardClan, public CardTactic
{
public :
	virtual void printCard() = 0;
	virtual string getNamecard() = 0;
	virtual void applyEffet() = 0;
	virtual ~CardElite() = default;
};

