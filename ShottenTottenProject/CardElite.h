#pragma once
#include"CardClan.h"
#include"CardTactic.h"

class CardElite : public CardClan, public CardTactic
{
public :
	virtual void printCard() = 0;
	virtual string getNamecard() = 0;
	virtual void applyEffet(unique_ptr<Border>& border) = 0;
	virtual ~CardElite() = default;
};

