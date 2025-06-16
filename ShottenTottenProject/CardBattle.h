#pragma once
#include "CardTactic.h"
#include "CollinMaillard.h"
#include "CBDecorator.h"
class CardBattle : public CardTactic
{
public:
	virtual void printCard() = 0;
	virtual void applyEffet(unique_ptr<Border>& border) = 0;
	virtual string getNamecard() = 0;
	virtual ~CardBattle() = default;
};