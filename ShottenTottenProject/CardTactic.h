#pragma once
#include "CardInterface.h"

class CardTactic : public CardInterface
{
public :
	virtual void printCard() = 0;
	virtual string getNamecard() = 0;
	virtual void applyEffet() = 0;
};

