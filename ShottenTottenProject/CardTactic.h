#pragma once
#include "CardInterface.h"
#include "Border.h"


class CardTactic : public CardInterface
{
public:
	virtual void printCard() = 0;
	virtual string getNamecard() = 0;
	virtual void applyEffet(unique_ptr<Border>& border) = 0;

	virtual ~CardTactic() = default;
};

