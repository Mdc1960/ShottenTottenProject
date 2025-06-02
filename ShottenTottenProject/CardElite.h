#pragma once
#include"CardClan.h"
#include"CardTactic.h"

class CardElite : public CardClan, public CardTactic
{
public :
	virtual void printCard() override;
	virtual string getNamecard() override;
	virtual void applyEffet() override;
};

