#pragma once
#include"CardClan.h"
#include"CardTactic.h"

class CardElite : public CardClan, public CardTactic
{
	virtual void applyEffet() = 0;
};

