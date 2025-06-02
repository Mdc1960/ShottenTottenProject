#pragma once
#include "CardTactic.h"

class Ruse : public CardTactic
{
public :
	void applyEffet() override;
	string getNamecard() override;
};

