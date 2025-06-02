#pragma once
#include "CardTactic.h"

class Ruse : public CardTactic
{
	virtual void applyEffet() = 0;
	virtual string getNamecard() = 0;
};

