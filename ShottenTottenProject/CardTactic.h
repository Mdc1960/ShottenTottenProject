#pragma once
#include "CardInterface.h"

class CardTactic : public CardInterface
{
	virtual void applyEffet() = 0;
};

